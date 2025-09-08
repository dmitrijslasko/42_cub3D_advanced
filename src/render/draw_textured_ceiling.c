#include "cub3d.h"

int draw_textured_ceiling(t_data *dt)
{
    t_texture texture = dt->map->textures[CEILING].texture;
    int x;
    int y;
    float rowDistance;

    y = dt->view->screen_center_y;

    while (y >= 0)
    {
		float fov_factor = tanf((FIELD_OF_VIEW_DEG * 0.635f) * (M_PI / 180.0f));

		float plane_x = dt->player.plane_x;
		float plane_y = dt->player.plane_y;

        // Calculate ray position relative to camera plane
        float rayDirX0 = dt->player.orientation_vector.x + plane_x;
        float rayDirY0 = dt->player.orientation_vector.y - plane_y;
        float rayDirX1 = dt->player.orientation_vector.x - plane_x;
        float rayDirY1 = dt->player.orientation_vector.y + plane_y;

        int p = y - dt->view->screen_center_y;
        rowDistance = ((0.5f * WINDOW_H) / p) / fov_factor;

        // Calculate step size for each screen pixel
        float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WINDOW_W;
        float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WINDOW_W;

        // Calculate initial floor intersection
        float floorX = rowDistance * rayDirX0 -  dt->player.pos.x ;
        float floorY = rowDistance * rayDirY0  - dt->player.pos.y;

        x = 0;
        while (x < WINDOW_W)
        {
			 // Calculate integer cell coordinates with stabilization
            int cellX = (int)(floorX);
            int cellY = (int)(floorY);

            // Calculate texture coordinates within cell
            int texX = (int)(TILE_SIZE * (floorX - cellX)) & (TILE_SIZE - 1);
            int texY = (int)(TILE_SIZE * (floorY - cellY)) & (TILE_SIZE - 1);

            // Get color and draw pixel
            uint32_t color = texture.texture_data[TILE_SIZE * texY + texX];
			apply_ambient_light_shading(*dt->ambient_light, &color);
            apply_distance_shadow(y / 4.0f, &color);
            img_pix_put(dt->raycasting_scene_img, x, y, color);

            floorX += floorStepX;
            floorY += floorStepY;
            x++;
        }
        y--;
    }
    return (0);
}
