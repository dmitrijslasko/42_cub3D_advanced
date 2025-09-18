#include "cub3d.h"

int draw_textured_floor(t_data *dt)
{
    t_texture texture = dt->map->textures[FLOOR].texture;
    int x;
    int current_row;
    char type;
    uint32_t color;

    float plane_x = dt->player.plane_x;
    float plane_y = dt->player.plane_y;

    // Calculate ray position relative to camera plane
    float rayDirX0 = dt->player.orientation_vector.x + plane_x;
    float rayDirY0 = dt->player.orientation_vector.y - plane_y;
    float rayDirX1 = dt->player.orientation_vector.x - plane_x;
    float rayDirY1 = dt->player.orientation_vector.y + plane_y;

    current_row = dt->view->screen_center_y;

    double adjustment = 0.6355f;
    double fov_factor = tanf((FIELD_OF_VIEW_DEG * adjustment) * (M_PI / 180.0f));
    // fov_factor = FIELD_OF_VIEW_SCALE;
    // printf("fov_factor: %f\n", fov_factor);

    while (current_row < WINDOW_H)
    {	
        int p = current_row - dt->view->screen_center_y;
        // printf("%f\n", dt->z_offset);
        float camera_height = ((0.5f - dt->z_offset / 2) * WINDOW_H);
        float rowDistance = (camera_height / p) / fov_factor;

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

            // Get color and draw pixel
            color = texture.texture_data[TILE_SIZE * texY + texX];
			apply_ambient_light_shading(*dt->ambient_light, &color);
            // apply_distance_shadow((WINDOW_H - current_row) / 4.0f, &color);
            // color = reduce_saturation(color, ((WINDOW_H - current_row) / (WINDOW_H)) * 2.0f);
            img_pix_put(dt->raycasting_scene_img, x, current_row, color);

            floorX += floorStepX;
            floorY += floorStepY;
            x++;
        }
        current_row++;
    }
    return (0);
}