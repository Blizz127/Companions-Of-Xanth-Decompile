/*
 * dos_mcb.c — DOS memory control block arena. See dos_mcb.h for why the
 * first-fit policy and the in-guest-memory layout both matter.
 *
 * On-disc MCB layout (16 bytes, at data_seg - 1):
 *   +0  byte  signature 'M' (more follow) or 'Z' (last)
 *   +1  word  owner PSP segment, 0 = free
 *   +3  word  size in paragraphs, NOT counting the MCB itself
 *   +5  3 bytes reserved
 *   +8  8 bytes owner name
 */
#include "dos_mcb.h"
#include "cpu86.h"   /* for the seg_r8/seg_w16 guest-memory accessors */

static inline uint8_t  mcb_sig(uint16_t seg)        { return seg_r8(seg, 0); }
static inline uint16_t mcb_owner(uint16_t seg)      { return seg_r16(seg, 1); }
static inline uint16_t mcb_size(uint16_t seg)       { return seg_r16(seg, 3); }

static inline void mcb_set(uint16_t seg, uint8_t sig, uint16_t owner, uint16_t size) {
    seg_w8(seg, 0, sig);
    seg_w16(seg, 1, owner);
    seg_w16(seg, 3, size);
    for (int i = 5; i < 16; i++) seg_w8(seg, (uint16_t)i, 0);
}

void mcb_init(mcb_arena *a, uint16_t start_seg, uint16_t end_seg) {
    a->first_mcb = start_seg;
    a->arena_end = end_seg;
    /* One free block covering everything after its own MCB paragraph. */
    mcb_set(start_seg, MCB_SIG_END, MCB_OWNER_FREE,
            (uint16_t)(end_seg - start_seg - 1));
}

void mcb_coalesce(mcb_arena *a) {
    uint16_t seg = a->first_mcb;
    for (;;) {
        uint8_t  sig  = mcb_sig(seg);
        uint16_t size = mcb_size(seg);
        uint16_t next;

        if (sig != MCB_SIG_MID) break;
        next = (uint16_t)(seg + size + 1);
        if (next >= a->arena_end) break;

        if (mcb_owner(seg) == MCB_OWNER_FREE && mcb_owner(next) == MCB_OWNER_FREE) {
            /* Absorb `next` (and inherit its end-of-chain status). */
            uint16_t merged = (uint16_t)(size + mcb_size(next) + 1);
            mcb_set(seg, mcb_sig(next), MCB_OWNER_FREE, merged);
            continue;   /* retry at the same block in case more follow */
        }
        seg = next;
    }
}

uint16_t mcb_largest_free(const mcb_arena *a) {
    uint16_t seg = a->first_mcb, best = 0;
    for (;;) {
        uint16_t size = mcb_size(seg);
        if (mcb_owner(seg) == MCB_OWNER_FREE && size > best) best = size;
        if (mcb_sig(seg) != MCB_SIG_MID) break;
        seg = (uint16_t)(seg + size + 1);
        if (seg >= a->arena_end) break;
    }
    return best;
}

uint32_t mcb_total_free(const mcb_arena *a) {
    uint16_t seg = a->first_mcb;
    uint32_t total = 0;
    for (;;) {
        uint16_t size = mcb_size(seg);
        if (mcb_owner(seg) == MCB_OWNER_FREE) total += size;
        if (mcb_sig(seg) != MCB_SIG_MID) break;
        seg = (uint16_t)(seg + size + 1);
        if (seg >= a->arena_end) break;
    }
    return total;
}

uint16_t mcb_alloc(mcb_arena *a, uint16_t para, uint16_t owner,
                   uint16_t *largest, uint16_t *err) {
    uint16_t seg = a->first_mcb;
    uint16_t big = 0;

    for (;;) {
        uint8_t  sig  = mcb_sig(seg);
        uint16_t size = mcb_size(seg);

        if (mcb_owner(seg) == MCB_OWNER_FREE) {
            if (size > big) big = size;
            if (size >= para) {
                /* First fit, lowest address — matches real DOS. */
                if (size > para + 1) {
                    /* Split: the remainder becomes a new free block. */
                    uint16_t rest_seg  = (uint16_t)(seg + para + 1);
                    uint16_t rest_size = (uint16_t)(size - para - 1);
                    mcb_set(rest_seg, sig, MCB_OWNER_FREE, rest_size);
                    mcb_set(seg, MCB_SIG_MID, owner, para);
                } else {
                    /* Exact (or one paragraph over) — hand over the block. */
                    mcb_set(seg, sig, owner, size);
                }
                if (largest) *largest = big;
                if (err) *err = 0;
                return (uint16_t)(seg + 1);
            }
        }
        if (sig != MCB_SIG_MID) break;
        seg = (uint16_t)(seg + size + 1);
        if (seg >= a->arena_end) break;
    }

    if (largest) *largest = big;
    if (err) *err = DOSERR_INSUFFICIENT_MEM;
    return 0;
}

uint16_t mcb_free(mcb_arena *a, uint16_t data_seg) {
    uint16_t seg = (uint16_t)(data_seg - 1);
    uint8_t sig;

    if (seg < a->first_mcb || seg >= a->arena_end) return DOSERR_INVALID_MCB;
    sig = mcb_sig(seg);
    if (sig != MCB_SIG_MID && sig != MCB_SIG_END) return DOSERR_INVALID_MCB;

    seg_w16(seg, 1, MCB_OWNER_FREE);
    mcb_coalesce(a);
    return 0;
}

uint16_t mcb_resize(mcb_arena *a, uint16_t data_seg, uint16_t para,
                    uint16_t *largest) {
    uint16_t seg = (uint16_t)(data_seg - 1);
    uint8_t  sig;
    uint16_t size;

    if (seg < a->first_mcb || seg >= a->arena_end) return DOSERR_INVALID_MCB;
    sig = mcb_sig(seg);
    if (sig != MCB_SIG_MID && sig != MCB_SIG_END) return DOSERR_INVALID_MCB;
    size = mcb_size(seg);

    if (para == size) {
        if (largest) *largest = size;
        return 0;
    }

    if (para < size) {
        /* Shrink: the tail becomes a free block. This is the CRT's first act
         * after startup, because maxalloc=FFFF gave it all of memory. */
        if (size - para >= 1) {
            uint16_t rest_seg  = (uint16_t)(seg + para + 1);
            uint16_t rest_size = (uint16_t)(size - para - 1);
            mcb_set(rest_seg, sig, MCB_OWNER_FREE, rest_size);
            mcb_set(seg, MCB_SIG_MID, mcb_owner(seg), para);
            mcb_coalesce(a);
        }
        if (largest) *largest = para;
        return 0;
    }

    /* Grow: only possible by absorbing a following free block. */
    if (sig == MCB_SIG_MID) {
        uint16_t next = (uint16_t)(seg + size + 1);
        if (next < a->arena_end && mcb_owner(next) == MCB_OWNER_FREE) {
            uint16_t combined = (uint16_t)(size + mcb_size(next) + 1);
            if (combined >= para) {
                uint8_t next_sig = mcb_sig(next);
                if (combined > para + 1) {
                    uint16_t rest_seg  = (uint16_t)(seg + para + 1);
                    uint16_t rest_size = (uint16_t)(combined - para - 1);
                    mcb_set(rest_seg, next_sig, MCB_OWNER_FREE, rest_size);
                    mcb_set(seg, MCB_SIG_MID, mcb_owner(seg), para);
                } else {
                    mcb_set(seg, next_sig, mcb_owner(seg), combined);
                }
                if (largest) *largest = para;
                return 0;
            }
            if (largest) *largest = combined;
            return DOSERR_INSUFFICIENT_MEM;
        }
    }

    if (largest) *largest = size;
    return DOSERR_INSUFFICIENT_MEM;
}

bool mcb_validate(const mcb_arena *a) {
    uint16_t seg = a->first_mcb;
    int guard = 0;

    for (;;) {
        uint8_t  sig  = mcb_sig(seg);
        uint16_t size = mcb_size(seg);

        if (sig != MCB_SIG_MID && sig != MCB_SIG_END) return false;
        if ((uint32_t)seg + size + 1u > a->arena_end) return false;
        if (sig == MCB_SIG_END) return true;

        seg = (uint16_t)(seg + size + 1);
        if (seg >= a->arena_end) return false;
        if (++guard > 65535) return false;   /* cycle in the chain */
    }
}
