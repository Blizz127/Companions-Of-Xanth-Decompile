/* Use SDL's dummy driver: no desktop window or owner-session interaction.
 * Include the video implementation to inspect its window/cursor lifecycle
 * without exposing renderer handles in the public HAL API. */
#include "../src/hal_video.c"

static int failures;
#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "mouse/video check failed at line %d: %s\n", __LINE__, #condition); \
    failures++; } } while (0)

int main(void) {
    int x, y, normal_x, normal_y;
    const int points[][2] = {{0, 0}, {107, 0}, {640, 400}, {1172, 799}, {1279, 799}};
    for (unsigned i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
        CHECK(hal_video_map_window_point(1280, 800, 1280, 800,
            HAL_VIDEO_PRESENT_ASPECT_4_3, points[i][0], points[i][1], &normal_x, &normal_y));
        CHECK(hal_video_map_window_point(1280, 800, 2560, 1600,
            HAL_VIDEO_PRESENT_ASPECT_4_3, points[i][0], points[i][1], &x, &y));
        /* Rounding of the odd-width viewport can differ by one guest pixel. */
        CHECK(abs(x - normal_x) <= 1 && y == normal_y);
    }
    CHECK(hal_video_map_window_point(1280, 800, 2560, 1600,
        HAL_VIDEO_PRESENT_ASPECT_4_3, 640, 400, &x, &y) && x == 160 && y == 100);
    CHECK(hal_video_map_window_point(1280, 800, 2560, 1600,
        HAL_VIDEO_PRESENT_PIXEL_INTEGER, 1279, 799, &x, &y) && x == 319 && y == 199);
    CHECK(hal_video_map_window_point(1280, 800, 2560, 1600,
        HAL_VIDEO_PRESENT_ASPECT_4_3, -5, -5, &x, &y) && x == 0 && y == 0);
    CHECK(!hal_video_map_window_point(0, 800, 2560, 1600,
        HAL_VIDEO_PRESENT_ASPECT_4_3, 1, 1, &x, &y));
#ifndef XANTH_HEADLESS_STUB
    const char *test_driver = getenv("XANTH_VIDEO_TEST_DRIVER");
    SDL_setenv("SDL_VIDEODRIVER", test_driver && *test_driver ? test_driver : "dummy", 1);
    CHECK(SDL_InitSubSystem(SDL_INIT_VIDEO) == 0);
    SDL_ShowCursor(SDL_ENABLE);
    CHECK(hal_video_init(4, false, false, false));
    CHECK(g_video.window != NULL && g_video.renderer != NULL);
    if (!g_video.window || !g_video.renderer) return 1;
#ifdef SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH
    CHECK(!strcmp(SDL_GetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH), "1"));
#endif
    uint32_t window_id = SDL_GetWindowID(g_video.window);
    hal_video_mouse_window_event(window_id, false);
    hal_video_set_window_size(1280, 800);
    CHECK(hal_video_map_mouse(640, 400, &x, &y) && x == 160 && y == 100);
    hal_video_mouse_window_event(window_id + 100, true);
    CHECK(SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE);
    hal_video_mouse_window_event(window_id, true);
    CHECK(SDL_ShowCursor(SDL_QUERY) == SDL_DISABLE);
    hal_video_mouse_window_event(window_id, true); /* Duplicate enter must not overwrite saved state. */
    hal_video_mouse_window_event(window_id, false);
    CHECK(SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE);
    hal_video_toggle_fullscreen();
    int window_w, window_h;
    SDL_GetWindowSize(g_video.window, &window_w, &window_h);
    CHECK(hal_video_map_mouse(window_w / 2, window_h / 2, &x, &y)
        && abs(x - 160) <= 1 && abs(y - 100) <= 1);
    hal_video_toggle_fullscreen();
    hal_video_mouse_window_event(window_id, true);
    hal_video_shutdown();
    CHECK(SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE);
    SDL_ShowCursor(SDL_DISABLE);
    CHECK(hal_video_init(2, false, false, false));
    window_id = SDL_GetWindowID(g_video.window);
    hal_video_mouse_window_event(window_id, true);
    hal_video_mouse_window_event(window_id, false);
    CHECK(SDL_ShowCursor(SDL_QUERY) == SDL_DISABLE);
    hal_video_shutdown();
    SDL_ShowCursor(SDL_ENABLE);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
#endif
    if (!failures) puts("Mouse geometry/DPI, resize/fullscreen, and host cursor lifecycle checks passed");
    return failures ? 1 : 0;
}
