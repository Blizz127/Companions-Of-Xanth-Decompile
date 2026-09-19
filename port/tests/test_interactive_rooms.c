#include "port_types.h"
#include "port_hal.h"
#include "port_engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    EngineConfig cfg = {0};
    cfg.headless = true;
    cfg.max_frames = 1000;
    cfg.has_max_frames = true;
    cfg.target_fps = 30.0;
    strncpy(cfg.data_path, "original", sizeof(cfg.data_path) - 1);

    EngineContext ctx = {0};
    if (engine_init(&ctx, &cfg) != 0) {
        fprintf(stderr, "Failed to init engine\n");
        return 1;
    }

    /* Fast-forward past intro into gameplay */
    ctx.frame_count = 430;
    engine_update_phase(&ctx);

    /* 1. Bedroom default (unopened envelope + post-it + authentic compass rose) */
    hal_video_save_bmp("/tmp/xanth_frames/state_bedroom_default.bmp");

    /* 2. Turn on computer monitor */
    ctx.monitor_on = true;
    ctx.frame_count = 450;
    engine_update_phase(&ctx);
    hal_video_save_bmp("/tmp/xanth_frames/state_bedroom_pc_on.bmp");

    /* 3. Open envelope */
    ctx.envelope_opened = true;
    ctx.score += 5;
    ctx.frame_count = 460;
    engine_update_phase(&ctx);
    hal_video_save_bmp("/tmp/xanth_frames/state_bedroom_envelope_open.bmp");

    /* 4. Go to Foyer (nw), open door, delivery package */
    ctx.current_room = 1;
    ctx.front_door_open = true;
    ctx.package_received = true;
    ctx.score += 10;
    ctx.frame_count = 470;
    engine_update_phase(&ctx);
    hal_video_save_bmp("/tmp/xanth_frames/state_foyer_door_open.bmp");

    /* 5. Go to Kitchen (west), open fridge with food */
    ctx.current_room = 2;
    ctx.fridge_open = true;
    ctx.score += 5;
    ctx.frame_count = 480;
    engine_update_phase(&ctx);
    hal_video_save_bmp("/tmp/xanth_frames/state_kitchen_fridge_open.bmp");

    engine_shutdown(&ctx);
    printf("[PASS] Interactive room states generated successfully.\n");
    return 0;
}
