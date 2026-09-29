/*
 * tool_mzdump.c — load an MZ image and report the relocated result.
 *
 * Exists so tests/test_mzload.py can perform the same load in Python
 * (via tools/identify.py + tools/mz.py) and assert the two agree exactly.
 * Any drift between the C loader the port ships and the Python reference the
 * decompilation pipeline trusts is a bug in one of them, and this is how we
 * find out which.
 *
 * Usage: tool_mzdump <file.exe> [load_seg_hex]
 */
#include "mzload.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint64_t fnv1a64(const uint8_t *p, size_t n) {
    uint64_t h = 1469598103934665603ULL;
    for (size_t i = 0; i < n; i++) {
        h ^= p[i];
        h *= 1099511628211ULL;
    }
    return h;
}

int main(int argc, char **argv) {
    mz_image_t img;
    char err[256] = {0};
    uint16_t load_seg = 0x1000;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <file.exe> [load_seg_hex]\n", argv[0]);
        return 2;
    }
    if (argc >= 3) load_seg = (uint16_t)strtoul(argv[2], NULL, 16);

    if (!mz_load_file(argv[1], load_seg, &img, err, sizeof(err))) {
        fprintf(stderr, "load failed: %s\n", err);
        return 1;
    }

    printf("{\n");
    printf("  \"load_seg\": %u,\n", img.load_seg);
    printf("  \"cblp\": %u, \"cp\": %u, \"crlc\": %u, \"cparhdr\": %u,\n",
           img.hdr.cblp, img.hdr.cp, img.hdr.crlc, img.hdr.cparhdr);
    printf("  \"minalloc\": %u, \"maxalloc\": %u,\n",
           img.hdr.minalloc, img.hdr.maxalloc);
    printf("  \"ss\": %u, \"sp\": %u, \"ip\": %u, \"cs\": %u, \"lfarlc\": %u,\n",
           img.hdr.ss, img.hdr.sp, img.hdr.ip, img.hdr.cs, img.hdr.lfarlc);
    printf("  \"header_bytes\": %u,\n", img.hdr.header_bytes);
    printf("  \"image_size\": %u,\n", img.hdr.image_size);
    printf("  \"tail_size\": %u,\n", img.hdr.tail_size);
    printf("  \"relocs_applied\": %u,\n", img.relocs_applied);
    printf("  \"entry_cs\": %u, \"entry_ip\": %u,\n", img.entry_cs, img.entry_ip);
    printf("  \"entry_ss\": %u, \"entry_sp\": %u,\n", img.entry_ss, img.entry_sp);
    printf("  \"image_fnv1a64\": \"%016llx\"\n",
           (unsigned long long)fnv1a64(g_dos_mem + (uint32_t)load_seg * 16u,
                                       img.hdr.image_size));
    printf("}\n");
    return 0;
}
