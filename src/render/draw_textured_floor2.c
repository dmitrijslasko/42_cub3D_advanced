#include "cub3d.h"

int draw_textured_floor2(t_data *dt)
{
   //FLOOR CASTING
   int h = dt->view->screen_center_y;
   float dirX = dt->player.direction_vector.x;
   float dirY = dt->player.direction_vector.y;
   float planeX = dt->player.plane_x;
   float planeY = dt->player.plane_y;
   float posX = dt->player.pos.x;
   float posY = dt->player.pos.y;

    for(int y = 0; y < h; y++)
    {
      // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
      float rayDirX0 = dirX - planeX;
      float rayDirY0 = dirY - planeY;
      float rayDirX1 = dirX + planeX;
      float rayDirY1 = dirY + planeY;

      // Current y position compared to the center of the screen (the horizon)
      int p = y - WINDOW_H / 2;

      // Vertical position of the camera.
      float posZ = 0.5 * WINDOW_H;

      // Horizontal distance from the camera to the floor for the current row.
      // 0.5 is the z position exactly in the middle between floor and ceiling.
      float rowDistance = posZ / p;

      // calculate the real world step vector we have to add for each x (parallel to camera plane)
      // adding step by step avoids multiplications with a weight in the inner loop
      float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WINDOW_W;
      float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WINDOW_W;

      // real world coordinates of the leftmost column. This will be updated as we step to the right.
      float floorX = posX + rowDistance * rayDirX0;
      float floorY = posY + rowDistance * rayDirY0;

      for(int x = 0; x < WINDOW_W; ++x)
      {
        // the cell coord is simply got from the integer parts of floorX and floorY
        int cellX = (int)(floorX);
        int cellY = (int)(floorY);

        // get the texture coordinate from the fractional part
        int tx = (int)(64 * (floorX - cellX)) & (64 - 1);
        int ty = (int)(64 * (floorY - cellY)) & (64 - 1);

        floorX += floorStepX;
        floorY += floorStepY;

        // choose texture and draw the pixel
        int floorTexture = 3;
        int ceilingTexture = 6;
        uint32_t color;

        // floor
        color = dt->map.textures[3].texture.texture_data[64 * ty + tx];
        // color = (color >> 1) & 8355711; // make a bit darker
        img_pix_put(dt->raycasting_scene_img, x, y, color);

        //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
        // color = texture[ceilingTexture][texWidth * ty + tx];
        // color = (color >> 1) & 8355711; // make a bit darker
        // buffer[screenHeight - y - 1][x] = color;
      }
    }
}