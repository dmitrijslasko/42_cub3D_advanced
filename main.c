#include <stdint.h>
#include <stdio.h>
#include <emscripten/emscripten.h>

#define WIDTH 640
#define HEIGHT 360
#define RED 0xFF0000
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
            framebuffer[y * WIDTH + x] = RED;
        }
    }
}

EMSCRIPTEN_KEEPALIVE
uint8_t *get_framebuffer(void)
{
    return (uint8_t *)framebuffer;
}