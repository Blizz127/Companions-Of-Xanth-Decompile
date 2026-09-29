/*
 * dos_mcb.h — DOS memory control block arena.
 *
 * This is load-bearing, not optional. XANTH.EXE has maxalloc=0xFFFF, so a
 * real DOS hands the program every free paragraph; the MS C startup then
 * shrinks its block with AH=4Ah, and RTLink allocates its overlay buffer out
 * of what is left with AH=48h. Get the layout wrong and either the CRT or
 * the overlay manager fails in a way that looks nothing like a memory bug.
 *
 * Two details matter for fidelity:
 *
 *  - MCBs live IN g_dos_mem, in the real 16-byte on-disc format, because the
 *    CRT's heap code may walk the chain rather than calling INT 21h.
 *  - Allocation is FIRST FIT, LOWEST ADDRESS, like real DOS. Best-fit would
 *    produce a different segment layout, and the overlay region sits at a
 *    fixed segment (0x30CB), so layout is observable.
 */
#ifndef EMU_DOS_MCB_H
#define EMU_DOS_MCB_H

#include "port_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MCB_SIG_MID   'M'   /* another MCB follows */
#define MCB_SIG_END   'Z'   /* last block in the chain */
#define MCB_OWNER_FREE 0x0000
#define MCB_OWNER_DOS  0x0008

/* DOS error codes the callers return in AX with CF set. */
#define DOSERR_INVALID_FUNCTION   0x0001
#define DOSERR_FILE_NOT_FOUND     0x0002
#define DOSERR_PATH_NOT_FOUND     0x0003
#define DOSERR_TOO_MANY_OPEN      0x0004
#define DOSERR_ACCESS_DENIED      0x0005
#define DOSERR_INVALID_HANDLE     0x0006
#define DOSERR_MCB_DESTROYED      0x0007
#define DOSERR_INSUFFICIENT_MEM   0x0008
#define DOSERR_INVALID_MCB        0x0009

typedef struct {
    uint16_t first_mcb;   /* segment of the first MCB in the chain */
    uint16_t arena_end;   /* first paragraph NOT available (e.g. 0xA000) */
} mcb_arena;

/* Build a single free block spanning [start_seg, end_seg). */
void mcb_init(mcb_arena *a, uint16_t start_seg, uint16_t end_seg);

/*
 * Allocate `para` paragraphs. Returns the segment of the DATA (one paragraph
 * past its MCB), or 0 on failure with *err set and *largest holding the
 * biggest block available — both the CRT and RTLink branch on that value.
 */
uint16_t mcb_alloc(mcb_arena *a, uint16_t para, uint16_t owner,
                   uint16_t *largest, uint16_t *err);

/* Free a block by its data segment. Returns a DOS error code, 0 on success. */
uint16_t mcb_free(mcb_arena *a, uint16_t data_seg);

/*
 * Resize in place. Growing consumes the following block if it is free and
 * large enough — which is exactly the shrink-then-grow dance the CRT and
 * RTLink perform. On failure returns an error code and sets *largest to the
 * maximum size actually achievable.
 */
uint16_t mcb_resize(mcb_arena *a, uint16_t data_seg, uint16_t para,
                    uint16_t *largest);

/* Merge adjacent free blocks. Called internally after every free/resize. */
void mcb_coalesce(mcb_arena *a);

/* Walk the chain and verify signatures and sizes. False means the guest has
 * corrupted it — worth checking at frame boundaries under --paranoid, so the
 * corruption is caught at the frame it happens. */
bool mcb_validate(const mcb_arena *a);

/* Largest free block, in paragraphs. */
uint16_t mcb_largest_free(const mcb_arena *a);

/* Total free paragraphs across all free blocks. */
uint32_t mcb_total_free(const mcb_arena *a);

#ifdef __cplusplus
}
#endif

#endif /* EMU_DOS_MCB_H */
