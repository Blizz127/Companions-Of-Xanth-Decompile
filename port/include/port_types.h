#ifndef PORT_TYPES_H
#define PORT_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Exact-Width DOS Integer Types
 * ------------------------------------------------------------------------- */
typedef int8_t    sbyte;
typedef uint8_t   ubyte;
typedef int16_t   sword;
typedef uint16_t  uword;
typedef int32_t   sdword;
typedef uint32_t  udword;

/* -------------------------------------------------------------------------
 * Calling Convention & Segment Attribute Stubs
 * ------------------------------------------------------------------------- */
#ifndef far
#define far
#endif

#ifndef near
#define near
#endif

#ifndef pascal
#define pascal
#endif

#ifndef cdecl
#define cdecl
#endif

#ifndef interrupt
#define interrupt
#endif

#ifndef __far
#define __far
#endif

#ifndef __near
#define __near
#endif

#ifndef __pascal
#define __pascal
#endif

#ifndef __cdecl
#define __cdecl
#endif

#ifndef __interrupt
#define __interrupt
#endif

/* -------------------------------------------------------------------------
 * 1 MB Virtual DOS Conventional Memory Space
 * ------------------------------------------------------------------------- */
#define DOS_MEM_SIZE (1024 * 1024)  /* 1,048,576 bytes */

extern uint8_t g_dos_mem[DOS_MEM_SIZE];

/* Key Architectural Segment Bases */
#define DOS_SEG_IVT     0x0000  /* Interrupt Vector Table */
#define DOS_SEG_BDA     0x0040  /* BIOS Data Area */
#define DOS_SEG_DOS     0x0050  /* DOS Communications Area */
#define DOS_SEG_CODE    0x1000  /* Root Executable Base */
#define DOS_SEG_OVERLAY 0x30CB  /* XANTH.OVL Load Segment */
#define DOS_SEG_VGA     0xA000  /* VGA Mode 13h Framebuffer (0xA000:0x0000) */

/* -------------------------------------------------------------------------
 * Segmented Pointer Virtualization & Bounds Checking
 * ------------------------------------------------------------------------- */
#define DOS_LINEAR_ADDR(seg, off) \
    (((uint32_t)((uint16_t)(seg)) << 4) + (uint16_t)(off))

static inline void *dos_mk_fp(uint16_t seg, uint16_t off) {
    uint32_t linear = DOS_LINEAR_ADDR(seg, off);
    if (linear >= DOS_MEM_SIZE) {
        return NULL;
    }
    return (void *)(g_dos_mem + linear);
}

static inline uint16_t dos_fp_seg(const void *ptr) {
    if (!ptr || (const uint8_t *)ptr < g_dos_mem || (const uint8_t *)ptr >= (g_dos_mem + DOS_MEM_SIZE)) {
        return 0;
    }
    uintptr_t linear = (uintptr_t)((const uint8_t *)ptr - g_dos_mem);
    return (uint16_t)(linear >> 4);
}

static inline uint16_t dos_fp_off(const void *ptr) {
    if (!ptr || (const uint8_t *)ptr < g_dos_mem || (const uint8_t *)ptr >= (g_dos_mem + DOS_MEM_SIZE)) {
        return 0;
    }
    uintptr_t linear = (uintptr_t)((const uint8_t *)ptr - g_dos_mem);
    return (uint16_t)(linear & 0x0F);
}

#define MK_FP(seg, off) dos_mk_fp((uint16_t)(seg), (uint16_t)(off))
#define FP_SEG(ptr)     dos_fp_seg((const void *)(ptr))
#define FP_OFF(ptr)     dos_fp_off((const void *)(ptr))

/* -------------------------------------------------------------------------
 * Endianness-Safe Read / Write Helpers
 * ------------------------------------------------------------------------- */
static inline uint16_t read_le16(const void *ptr) {
    const uint8_t *b = (const uint8_t *)ptr;
    return (uint16_t)(b[0] | ((uint16_t)b[1] << 8));
}

static inline uint32_t read_le32(const void *ptr) {
    const uint8_t *b = (const uint8_t *)ptr;
    return (uint32_t)(b[0] | ((uint32_t)b[1] << 8) | ((uint32_t)b[2] << 16) | ((uint32_t)b[3] << 24));
}

static inline void write_le16(void *ptr, uint16_t val) {
    uint8_t *b = (uint8_t *)ptr;
    b[0] = (uint8_t)(val & 0xFF);
    b[1] = (uint8_t)((val >> 8) & 0xFF);
}

static inline void write_le32(void *ptr, uint32_t val) {
    uint8_t *b = (uint8_t *)ptr;
    b[0] = (uint8_t)(val & 0xFF);
    b[1] = (uint8_t)((val >> 8) & 0xFF);
    b[2] = (uint8_t)((val >> 16) & 0xFF);
    b[3] = (uint8_t)((val >> 24) & 0xFF);
}

#ifdef __cplusplus
}
#endif

#endif /* PORT_TYPES_H */
