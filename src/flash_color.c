#include "cub3d.h"

int flash_color(t_data *dt, int color)
{
    int x;
    int y;

    y = 0;
    while (y < WINDOW_H)
    {
        x = 0;
        while (x < WINDOW_W)
        {
            img_pix_put(dt->final_frame_img, x, y, color);
            x++;
        }
        y++;
    }

}