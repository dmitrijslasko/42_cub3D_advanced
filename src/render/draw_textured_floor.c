#include "cub3d.h"

int draw_textured_floor(t_data *dt)
{
    t_texture texture;
    int x;
    int current_row;
    char type;
    uint32_t color;

    current_row = dt->view->screen_center_y;

    float plane_x = dt->player.plane_x;
    float plane_y = dt->player.plane_y;

    // Calculate ray position relative to camera plane
    float rayDirX0 = dt->player.direction_vector.x + plane_x;
    float rayDirY0 = dt->player.direction_vector.y - plane_y;
    float rayDirX1 = dt->player.direction_vector.x - plane_x;
    float rayDirY1 = dt->player.direction_vector.y + plane_y;

    while (current_row < WINDOW_H)
    {
        float adjustment = 0.6354f;
		float fov_factor = tanf((FIELD_OF_VIEW_DEG * adjustment) * (M_PI / 180.0f));

        int p = current_row - dt->view->screen_center_y;
        float rowDistance = ((0.5f * WINDOW_H) / p) / fov_factor;

        // Calculate step size for each screen pixel
        float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WINDOW_W;
        float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WINDOW_W;

        // Calculate initial floor intersection
        float floorX = dt->player.pos.x + rowDistance * rayDirX0;
        float floorY = dt->player.pos.y + rowDistance * rayDirY0;

        x = 0;
        while (x < WINDOW_W)
        {
			 // Calculate integer cell coordinates with stabilization
            int cellX = (int)(floorX);
            int cellY = (int)(floorY);

            // Calculate texture coordinates within cell
            int texX = (int)(TILE_SIZE * (floorX - cellX)) & (TILE_SIZE - 1);
            int texY = (int)(TILE_SIZE * (floorY - cellY)) & (TILE_SIZE - 1);
            
            // texture = get_curr_level(dt)->map.textures[FLOOR].texture;
            texture = dt->levels[0].map.textures->texture;

            // Get color and draw pixel
            color = texture.texture_data[TILE_SIZE * texY + texX];
            // color = BLUE;
			// apply_distance_shadow_distance(*dt->ambient_light, &color);
            img_pix_put(dt->raycasting_scene_img, x, current_row, color);

            floorX += floorStepX;
            floorY += floorStepY;
            x++;
        }
        current_row++;
    }
    return (0);
}
