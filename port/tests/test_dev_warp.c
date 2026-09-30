/* Asset-free regression of the dev-menu warp executor (dev_warp.c): the
 * checkpoint list, the region/area/spot tree, and the restore macro's
 * safety rules -- keys only at field idle, the label typed only while the
 * Restore dialog owns input, and the temporary save slot always removed. */
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif
#include "dev_warp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

static bool g_idle, g_modal;
static char g_keys[64];
static int g_nkeys;
static void post_key(uint8_t scan, uint8_t ascii) {
    (void)scan;
    if (g_nkeys < 63) g_keys[g_nkeys++] = (char)ascii;
    g_keys[g_nkeys] = '\0';
}
static bool field_idle(void) { return g_idle; }
static bool game_modal(void) { return g_modal; }

static char g_ck[64], g_saves[64];

static void write_file(const char *dir, const char *name, const char *text) {
    char path[256];
    FILE *f;
    snprintf(path, sizeof(path), "%s/%s", dir, name);
    f = fopen(path, "w");
    CHECK(f);
    fputs(text, f);
    fclose(f);
}

static bool exists(const char *dir, const char *name) {
    char path[256];
    snprintf(path, sizeof(path), "%s/%s", dir, name);
    return access(path, F_OK) == 0;
}

static void load(void) {
    dev_warp_host h;
    memset(&h, 0, sizeof(h));
    h.field_idle = field_idle;
    h.game_modal = game_modal;
    h.post_key = post_key;
    snprintf(h.save_dir, sizeof(h.save_dir), "%s", g_saves);
    snprintf(h.checkpoint_dir, sizeof(h.checkpoint_dir), "%s", g_ck);
    dev_warp_reset_for_tests();
    dev_warp_load(&h, false);
    g_idle = g_modal = false;
    g_nkeys = 0; g_keys[0] = '\0';
}

static dev_warp_status run(int frames) {
    dev_warp_status st = DEV_WARP_RUNNING;
    for (int i = 0; i < frames && st == DEV_WARP_RUNNING; ++i) st = dev_warp_tick();
    return st;
}

int main(void) {
    char msg[128];
    int idx[8];
    snprintf(g_ck, sizeof(g_ck), "/tmp/xanth-ck-XXXXXX");
    snprintf(g_saves, sizeof(g_saves), "/tmp/xanth-sv-XXXXXX");
    CHECK(mkdtemp(g_ck) && mkdtemp(g_saves));
    write_file(g_ck, "checkpoints.txt",
        "# id\tlabel\tregion\tarea\tspot\tverified\tsha256\n"
        "home\thome\tMundania\tYour house\tBedroom\t1\taaa9402664f1a41f40ebbc52c9993eb66aeb366602958fdfaa283b71e64db123\n"
        "cave\tcave\tXanth\tCavern\tCavern (with Nada)\t1\t2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6\n"
        "spring\tspr\tXanth\tCavern\tSpring\t1\t043a718774c572bd8a25adbeb1bfcd5c0256ae11cecf9f9c3f925d0e52beaf89\n"
        "draft\tdrf\tXanth\tVoid\tShimmer\t0\t18ac3e7343f016890c510e93f935261169d9e3f565436429830faf0934f4f8e4\n"
        "missing\tmis\tXanth\tVoid\tGone\t1\t-\n");
    write_file(g_ck, "home.SAV", "h"); write_file(g_ck, "cave.SAV", "c");
    write_file(g_ck, "spring.SAV", "s"); write_file(g_ck, "draft.SAV", "d");

    /* Only verified entries with a save file are offered. */
    load();
    CHECK(dev_warp_count() == 3);
    CHECK(dev_warp_find("draft") < 0 && dev_warp_find("missing") < 0);
    CHECK(dev_warp_regions(idx, 8) == 2);
    CHECK(!strcmp(dev_warp_get(idx[0])->region, "Mundania"));
    CHECK(dev_warp_areas("Xanth", idx, 8) == 1);
    CHECK(dev_warp_spots("Xanth", "Cavern", idx, 8) == 2);

    /* Happy path: R at idle, label only while modal, Enter, slot removed. */
    CHECK(dev_warp_request(dev_warp_find("cave"), msg, sizeof(msg)));
    CHECK(exists(g_saves, "XANTH000.SAV"));
    CHECK(run(5) == DEV_WARP_RUNNING && g_nkeys == 0);   /* not idle yet */
    g_idle = true;
    CHECK(run(1) == DEV_WARP_RUNNING && !strcmp(g_keys, "r"));
    g_idle = false;                                       /* key being handled */
    CHECK(run(20) == DEV_WARP_RUNNING && !strcmp(g_keys, "r"));  /* no modal: no typing */
    g_modal = true;
    CHECK(run(40) == DEV_WARP_RUNNING);
    CHECK(!strcmp(g_keys, "rcave\r"));
    g_modal = false; g_idle = true;
    CHECK(run(40) == DEV_WARP_DONE);
    CHECK(!exists(g_saves, "XANTH000.SAV"));
    CHECK(dev_warp_used() && strstr(dev_warp_message(), "Warped to Cavern"));
    CHECK(exists(g_saves, "xanth-dev-menu.log"));

    /* Changes after list verification cannot reach the Restore dialog. */
    load();
    write_file(g_ck, "home.SAV", "changed");
    CHECK(!dev_warp_request(dev_warp_find("home"), msg, sizeof(msg)));
    CHECK(strstr(msg, "changed since verification") && g_nkeys == 0);
    write_file(g_ck, "home.SAV", "h");
    load();
    CHECK(dev_warp_request(dev_warp_find("home"), msg, sizeof(msg)));
    CHECK(exists(g_saves, "XANTH000.SAV"));
    dev_warp_shutdown();
    CHECK(!dev_warp_active() && !exists(g_saves, "XANTH000.SAV"));

    /* Never idle: refused, nothing typed, slot removed. */
    load();
    CHECK(dev_warp_request(dev_warp_find("home"), msg, sizeof(msg)));
    CHECK(run(2000) == DEV_WARP_FAILED && g_nkeys == 0);
    CHECK(strstr(dev_warp_message(), "not idle") && !exists(g_saves, "XANTH000.SAV"));

    /* R does not open the dialog: fail without typing the label. */
    load();
    CHECK(dev_warp_request(dev_warp_find("home"), msg, sizeof(msg)));
    g_idle = true;
    CHECK(run(2000) == DEV_WARP_FAILED && !strcmp(g_keys, "r"));
    CHECK(strstr(dev_warp_message(), "did not open") && !exists(g_saves, "XANTH000.SAV"));

    /* The dialog closes mid-label: stop typing at once. */
    load();
    CHECK(dev_warp_request(dev_warp_find("spring"), msg, sizeof(msg)));
    g_idle = true; run(1); g_idle = false; g_modal = true;
    run(15);                                              /* settle, start typing */
    g_modal = false;
    CHECK(run(50) == DEV_WARP_FAILED);
    CHECK(strchr(g_keys, '\r') == NULL);                  /* never pressed Enter */
    CHECK(!exists(g_saves, "XANTH000.SAV"));

    /* An existing user save keeps its slot; the warp takes the next free one. */
    load();
    write_file(g_saves, "XANTH000.SAV", "user");
    CHECK(dev_warp_request(dev_warp_find("home"), msg, sizeof(msg)));
    CHECK(exists(g_saves, "XANTH001.SAV"));
    CHECK(!dev_warp_request(dev_warp_find("cave"), msg, sizeof(msg)));  /* one at a time */
    dev_warp_reset_for_tests();
    CHECK(exists(g_saves, "XANTH000.SAV") && !exists(g_saves, "XANTH001.SAV"));

    /* Story steps: detection from the live room, score and item count.
     * s2 scores 15; s3 scores nothing but adds items; s4 scores nothing and
     * changes nothing observable (never offered); s5 scores again. */
    write_file(g_ck, "checkpoints.txt",
        "s1\ta\tMundania\tHouse\tKitchen\t1\t6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b\t64\t5\t1\tFind the kitchen\t2\n"
        "s2\tb\tMundania\tHouse\tKitchen\t1\td4735e3a265e16eee03f59718b9b5d03019c07d8b6c51f90da3a666eec13ab35\t64\t20\t2\tPhone\t2\n"
        "s3\tc\tMundania\tHouse\tKitchen\t1\t4e07408562bedb8b60ce05c1decfe3ad16b72230967de01f640b7e4729b49fce\t64\t20\t3\tSupplies\t5\n"
        "s4\td\tMundania\tHouse\tKitchen\t1\t4b227777d4dd1fc61c6f884f48641d02b4d121d3fd328cb08b5531fcacdabf8a\t64\t20\t4\tIdle\t5\n"
        "s5\te\tXanth\tCavern\tCave\t1\tef2d127de37b942baad06145e54b0c619a1f22327b2ebbcfbec78f5564afe39d\t9\t40\t5\tCavern\t5\n");
    write_file(g_ck, "s1.SAV", "1"); write_file(g_ck, "s2.SAV", "2");
    write_file(g_ck, "s3.SAV", "3"); write_file(g_ck, "s4.SAV", "4"); write_file(g_ck, "s5.SAV", "5");
    load();
    CHECK(dev_warp_current_step(34, 0, 2) == dev_warp_find("s1"));   /* fresh game */
    CHECK(dev_warp_current_step(51, 3, 2) == dev_warp_find("s1"));   /* mid step 1 */
    CHECK(dev_warp_current_step(64, 5, 2) == dev_warp_find("s2"));   /* at step 2's start */
    CHECK(dev_warp_current_step(51, 5, 3) == -1);                    /* score 5 elsewhere: unknown */
    CHECK(dev_warp_current_step(64, 20, 2) == dev_warp_find("s3"));  /* supplies not yet taken */
    /* s4 cannot be told apart from its start, so the next detectable step is
     * s5, whose recorded end already includes s4. */
    CHECK(dev_warp_current_step(64, 20, 5) == dev_warp_find("s5"));
    CHECK(dev_warp_current_step(12, 25, 5) == dev_warp_find("s5"));
    CHECK(dev_warp_current_step(9, 40, 5) == -1);                    /* past the recorded route */
    CHECK(dev_warp_area_end("Mundania", "House") == dev_warp_find("s4"));
    CHECK(dev_warp_area_end("Xanth", "Cavern") == dev_warp_find("s5"));
    CHECK(dev_warp_step(2) == dev_warp_find("s2") && dev_warp_step(9) == -1);
    {
        static const char *extra[] = { "s1.SAV", "s2.SAV", "s3.SAV", "s4.SAV", "s5.SAV" };
        char path[256];
        for (size_t i = 0; i < 5; ++i) { snprintf(path, sizeof(path), "%s/%s", g_ck, extra[i]); unlink(path); }
    }

    {
        static const char *ck_files[] = { "checkpoints.txt", "home.SAV", "cave.SAV", "spring.SAV", "draft.SAV" };
        static const char *sv_files[] = { "XANTH000.SAV", "xanth-dev-menu.log" };
        char path[256];
        for (size_t i = 0; i < sizeof(ck_files) / sizeof(ck_files[0]); ++i) {
            snprintf(path, sizeof(path), "%s/%s", g_ck, ck_files[i]); unlink(path);
        }
        for (size_t i = 0; i < sizeof(sv_files) / sizeof(sv_files[0]); ++i) {
            snprintf(path, sizeof(path), "%s/%s", g_saves, sv_files[i]); unlink(path);
        }
        rmdir(g_ck); rmdir(g_saves);
    }
    puts("dev warp tests passed");
    return 0;
}
