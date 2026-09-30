/* Retail click integration driver: reuse the normal trace interpreter, but
 * route mouse input through actual SDL events, HAL FIFO, and paced guest
 * frames. SDL dummy keeps this invisible to the owner's desktop. */
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "vm.h"
#include "port_hal.h"
#include <stdio.h>
static int last_x = -1, last_y = -1, last_buttons;
static uint64_t guest_frames, button_edges;
static int input_x=160,input_y=100;
static uint64_t edge_poll_sequence;
static bool await_poll;
static uint64_t edge_frame;
static void sdl_move(vm *v, int x, int y) {
    (void)v;
    SDL_Event event = {0};
    event.type = SDL_MOUSEMOTION;
    event.motion.x = x; event.motion.y = y;
    input_x=x; input_y=y;
    if (SDL_PushEvent(&event) < 0) abort();
}
static void sdl_button(vm *v, int button, bool down) {
    (void)v;
    SDL_Event event = {0};
    event.type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
    event.button.button = button == 0 ? SDL_BUTTON_LEFT :
                          button == 1 ? SDL_BUTTON_RIGHT : SDL_BUTTON_MIDDLE;
    /* SDL events preserve the coordinates at each button edge. */
    event.button.x = input_x; event.button.y = input_y;
    if (SDL_PushEvent(&event) < 0) abort();
}
static bool paced_run(vm *v, uint64_t budget) {
    uint64_t finish = v->insn_count + budget;
    while (v->insn_count < finish) {
        int x,y,buttons,key;
        hal_input_poll(&x,&y,&buttons,&key);
        if(await_poll && v->mouse_poll_sequence != edge_poll_sequence) {
            fprintf(stderr,"[SDL bridge] state %d observed after %llu frames\n",
                last_buttons,(unsigned long long)(guest_frames-edge_frame));
            await_poll=false;
        }
        hal_pointer_event pointer;
        while (!await_poll && hal_input_take_pointer_event(&pointer)) {
            if (pointer.x != last_x || pointer.y != last_y) {
                vm_post_mouse_move(v,pointer.x,pointer.y);
                last_x=pointer.x; last_y=pointer.y;
            }
            int changed = pointer.buttons ^ last_buttons;
            for (int b=0;b<3;b++)
                if (changed & (1<<b)) vm_post_mouse_button(v,b,(pointer.buttons&(1<<b))!=0);
            last_buttons=pointer.buttons;
            if (changed) {
                button_edges++;
                edge_poll_sequence=v->mouse_poll_sequence;
                edge_frame=guest_frames;
                await_poll=true;
                break;
            }
        }
        uint64_t target = v->cpu.cycles + v->cycles_per_second / 60;
        do {
            uint64_t count = (target-v->cpu.cycles)/4+1;
            if (count > finish-v->insn_count) count=finish-v->insn_count;
            if (!vm_run(v,count)) return false;
            if (v->waiting_for_input) break;
        } while (v->cpu.cycles < target && v->insn_count < finish);
        guest_frames++;

        /* Match the trace driver's blocking-read behavior; do not spin if
         * the guest cannot spend the remaining instruction budget. */
        if (v->waiting_for_input) return true;
    }
    return true;
}
#define vm_post_mouse_move sdl_move
#define vm_post_mouse_button sdl_button
#define vm_run paced_run
#define main trace_driver_main
#include "tool_vmboot.c"
#undef main
#undef vm_run
#undef vm_post_mouse_move
#undef vm_post_mouse_button
int main(int argc,char **argv) {
    const char *test_driver = getenv("XANTH_VIDEO_TEST_DRIVER");
    SDL_setenv("SDL_VIDEODRIVER",test_driver && *test_driver ? test_driver : "dummy",1);
    SDL_setenv("SDL_AUDIODRIVER","dummy",1);
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS)<0 ||
        !hal_video_init(1,false,false,false)) return 2;
    /* A 320x200 square-pixel window makes trace guest coordinates identical
     * to SDL window coordinates; mapping still traverses the actual HAL. */
    hal_video_set_present_mode(HAL_VIDEO_PRESENT_PIXEL_INTEGER);
    hal_input_init();
    hal_input_enable_pointer_events(true);
    int result=trace_driver_main(argc,argv);
    fprintf(stderr,"[SDL bridge] guest frames=%llu button edges=%llu\n",
        (unsigned long long)guest_frames,(unsigned long long)button_edges);
    hal_input_shutdown(); hal_video_shutdown(); SDL_Quit();
    return result;
}
