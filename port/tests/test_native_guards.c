/* Exercise hashed guards against user-owned runtime bytes, never embedded bytes.
 * Whitebox inclusion makes guard offset metadata available without exposing
 * a release API or copying raw retail instruction fixtures into this test. */
#include "../src/emu/native_stage2.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    vm machine;
    vm_config cfg = {0};
    char error[512], digest[65];
    const struct { uint32_t offset; size_t size; } extents[] = {
        {EXE_136552_OFFSET, 4u},
        {EXE_52710_OFFSET, 10u},
        {EXE_112795_OFFSET, 58u},
        {EXE_52674_OFFSET, 13u},
        {EXE_112711_OFFSET, 84u},
        {EXE_34775_OFFSET, 42u},
        {ADD_MOD_EXE_OFFSET, 37u},
        {SET_FIELDS_EXE_OFFSET, 22u},
        {EXE_112853_OFFSET, 52u},
        {EXE_100016_OFFSET, 70u},
        {EXE_103774_OFFSET, 54u},
        {EXE_100203_OFFSET, 5u},
        {EXE_103744_OFFSET, 13u},
        {SET_INT_AND_ZERO_EXE_OFFSET, 17u},
        {SET_FAR_PTR_EXE_OFFSET, 18u},
        {EXE_94712_EXE_OFFSET, 39u},
        {IF0_HELPER_INC_EXE_OFFSET, 7u},
        {EXE_14360_EXE_OFFSET, 22u},
        {SET_FAR_ARR_EXE_OFFSET, 26u},
        {GET_FAR_IDX_EXE_OFFSET, 29u},
        {EXE_99679_EXE_OFFSET, 48u},
        {EXE_86810_EXE_OFFSET, 4u},
        {EXE_84866_EXE_OFFSET, 8u},
        {SET_INT_PAIR_A_EXE_OFFSET, 17u},
        {SET_INT_PAIR_B_EXE_OFFSET, 17u},
        {SET_INT_A_EXE_OFFSET, 11u},
        {SET_INT_B_EXE_OFFSET, 11u},
        {CLEAR_BYTE_EXE_OFFSET, 12u},
        {SWAP_INT_EXE_OFFSET, 25u},
        {EXE_115346_OFFSET, 13u},
        {ARR_SET_ONE_OFFSET, 23u},
        {EXE_114942_OFFSET, 50u},
        {STORE_TWO_GLOBALS_OFFSET, 23u},
        {SET_INT_IF_GE0_OFFSET, 17u},
        {IABS_OFFSET, 13u},
        {SET_FAR_ARR_CHK_OFFSET, 40u},
    };
    if (argc != 4) { fprintf(stderr, "usage: %s EXE DATA SAVES\n", argv[0]); return 2; }
    if (!xanth_sha256_buffer(NULL, 0, digest) ||
        strcmp(digest, "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855")) return 1;
    if (!xanth_sha256_buffer("abc", 3, digest) ||
        strcmp(digest, "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad")) return 1;
    snprintf(cfg.exe_path, sizeof(cfg.exe_path), "%s", argv[1]);
    snprintf(cfg.data_dir, sizeof(cfg.data_dir), "%s", argv[2]);
    snprintf(cfg.save_dir, sizeof(cfg.save_dir), "%s", argv[3]);
    if (!vm_init(&machine, &cfg, error, sizeof(error))) {
        fprintf(stderr, "VM initialization failed: %s\n", error); return 1;
    }
    if (!xanth_native_stage2_install(&machine)) return 1;
    size_t tested = 0;
    for (size_t e = 0; e < sizeof(extents) / sizeof(extents[0]); e++) {
        for (size_t i = 0; i < extents[e].size; i++) {
            uint32_t address = (uint32_t)machine.img.load_seg * 16u + extents[e].offset + (uint32_t)i;
            uint8_t saved = mem_r8(address);
            cpu86_hook_clear_all();
            mem_w8(address, (uint8_t)(saved ^ 1u));
            bool accepted = xanth_native_stage2_install(&machine);
            mem_w8(address, saved);
            if (accepted) {
                fprintf(stderr, "Mutated native extent accepted: offset %u byte %zu\n", extents[e].offset, i);
                vm_shutdown(&machine); return 1;
            }
            tested++;
        }
    }
    cpu86_hook_clear_all();
    if (!xanth_native_stage2_install(&machine)) return 1;
    vm_shutdown(&machine);
    printf("Hashed native guards: %zu extents, %zu byte mutations rejected; relocated words and SHA vectors verified\n",
        sizeof(extents) / sizeof(extents[0]), tested);
    return 0;
}
