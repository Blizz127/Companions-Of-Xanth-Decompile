/* LD_PRELOAD test shim for real-time input gates: injects Space presses
 * into SDL_PollEvent at given frame counts (SHIM_KEY_FRAMES="300,900").
 * A frame is counted each time the real queue comes back empty, which is
 * once per xanth_port frame. Test-only; never linked into or shipped with
 * the port, and it drives the unmodified binary through its own SDL input. */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SDL.h>
static int (*real_poll)(SDL_Event *);
static long frames, targets[16]; static int ntargets = -1, pending_up = 0, next_t = 0;
int SDL_PollEvent(SDL_Event *e) {
    if (!real_poll) real_poll = (int (*)(SDL_Event *))dlsym(RTLD_NEXT, "SDL_PollEvent");
    if (ntargets < 0) {
        char buf[256]; const char *s = getenv("SHIM_KEY_FRAMES"); ntargets = 0;
        if (s) { snprintf(buf, sizeof(buf), "%s", s);
            for (char *t = strtok(buf, ","); t && ntargets < 16; t = strtok(NULL, ",")) targets[ntargets++] = atol(t); }
    }
    int r = real_poll(e);
    if (r) return r;
    frames++;
    if (pending_up && frames >= pending_up) {
        memset(e, 0, sizeof(*e)); e->type = SDL_KEYUP; e->key.state = SDL_RELEASED;
        e->key.keysym.sym = SDLK_SPACE; e->key.keysym.scancode = SDL_SCANCODE_SPACE;
        pending_up = 0; return 1;
    }
    if (next_t < ntargets && frames >= targets[next_t]) {
        memset(e, 0, sizeof(*e)); e->type = SDL_KEYDOWN; e->key.state = SDL_PRESSED;
        e->key.keysym.sym = SDLK_SPACE; e->key.keysym.scancode = SDL_SCANCODE_SPACE;
        fprintf(stderr, "[keyshim] Space at frame %ld\n", frames);
        next_t++; pending_up = frames + 4; return 1;
    }
    return 0;
}
