/*
 * dos_mem.c — the guest's 1 MB conventional memory space.
 *
 * This lives in its own translation unit (rather than in hal_video.c, where
 * it started) so that the emulation core and the SDL-free conformance test
 * binary can link against it without dragging in SDL.
 *
 * Zero-initialised deliberately: deterministic replay requires that the guest
 * can never read an uninitialised byte and have it influence a frame hash.
 */
#include "port_types.h"

uint8_t g_dos_mem[DOS_MEM_SIZE] = {0};
