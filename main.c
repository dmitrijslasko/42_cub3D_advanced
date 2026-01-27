#include <stdint.h>
#include <stdio.h>
#include <emscripten/emscripten.h>

#define WIDTH 640
#define HEIGHT 360

static uint32_t framebuffer[WIDTH * HEIGHT];

EMSCRIPTEN_KEEPALIVE
void game_step(float dt)
{
    static int once = 0;

    if (!once) {
        once = 1;
        puts("HELLO FROM C");
    }

    (void)dt;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            framebuffer[y * WIDTH + x] =
                (uint32_t)(0 | (0 << 8) | (0 << 16) | (255 << 24));
        }
    }

    int max_size = (WIDTH < HEIGHT) ? WIDTH : HEIGHT;
    int size = rect_size;
    if (size > max_size) {
        size = max_size;
    }
    int x0 = rect_x;
    int y0 = rect_y;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x0 + size > WIDTH) x0 = WIDTH - size;
    if (y0 + size > HEIGHT) y0 = HEIGHT - size;
    if (texture_rgba && tex_w > 0 && tex_h > 0) {
        for (int y = y0; y < y0 + size; y++) {
            for (int x = x0; x < x0 + size; x++) {
                int u = (x - x0) * tex_w / size;
                int v = (y - y0) * tex_h / size;
                int idx = (v * tex_w + u) * 4;
                uint8_t r = texture_rgba[idx + 0];
                uint8_t g = texture_rgba[idx + 1];
                uint8_t b = texture_rgba[idx + 2];
                uint8_t a = texture_rgba[idx + 3];
                framebuffer[y * WIDTH + x] =
                    (uint32_t)(r | (g << 8) | (b << 16) | (a << 24));
            }
        }
    } else {
        uint32_t color =
            (uint32_t)(current_r | (current_g << 8) | (current_b << 16) | (current_a << 24));
        for (int y = y0; y < y0 + size; y++) {
            for (int x = x0; x < x0 + size; x++) {
                framebuffer[y * WIDTH + x] = color;
            }
        }
    }
}

EMSCRIPTEN_KEEPALIVE
uint8_t *get_framebuffer(void)
{
    return (uint8_t *)framebuffer;
}