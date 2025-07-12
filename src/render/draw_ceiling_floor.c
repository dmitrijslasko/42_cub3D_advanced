/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/12 20:43:19 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_ceiling(t_data *dt)
{
	int			color;
	t_coor		top_left;
	t_coor		bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, WINDOW_W, dt->view->screen_center_y);
	color = create_color_rgb(dt->map.wall_tile[CEILING].color.r, \
							dt->map.wall_tile[CEILING].color.g, \
							dt->map.wall_tile[CEILING].color.b);
	draw_rectangle(dt->raycasting_scene_img, top_left, bottom_right, color);
	return (EXIT_SUCCESS);
}

int	draw_floor(t_data *dt)
{
	int		color;
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, dt->view->screen_center_y);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H);
	color = create_color_rgb(	dt->map.wall_tile[FLOOR].color.r, \
								dt->map.wall_tile[FLOOR].color.g,
								dt->map.wall_tile[FLOOR].color.b);
	draw_rectangle(dt->raycasting_scene_img, top_left, bottom_right, color);
	return (EXIT_SUCCESS);
}

int	apply_distance_shadow_floor(int distance, int *color)
{
	float	shade;
	int		r;
	int		g;
	int		b;

	shade = 1.0f / (1.0f + distance * DISTANCE_SHADOW_STRENGTH);
	if (shade < 0.1f)
		shade = 0.1f;
	r = ((*color >> 16) & 0xFF) * shade;
	g = ((*color >> 8) & 0xFF) * shade;
	b = ((*color >> 0) & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | (b << 0);
	return (EXIT_SUCCESS);
}

int draw_textured_floor(t_data *dt)
{
    t_texture texture = dt->map.wall_tile[8].texture;
    int x, y;

    y = dt->view->screen_center_y;

    float plane_x = dt->player.plane_x;
    float plane_y = dt->player.plane_y;

    // Calculate ray position relative to camera plane
    float rayDirX0 = dt->player.direction_vector.x + plane_x;
    float rayDirY0 = dt->player.direction_vector.y - plane_y;
    float rayDirX1 = dt->player.direction_vector.x - plane_x;
    float rayDirY1 = dt->player.direction_vector.y + plane_y;

    while (y < WINDOW_H)
    {
        float adjustment;
        
        adjustment = 0.635f;
		float fov_factor = tanf((FIELD_OF_VIEW_DEG * adjustment) * (M_PI / 180.0f));
        
        int p = y - dt->view->screen_center_y;
        printf("%f\n", fov_factor);
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

            // Get color and draw pixel
            uint32_t color = texture.texture_data[TILE_SIZE * texY + texX];
			// apply_distance_shadow_floor(100, &color);
            img_pix_put(dt->raycasting_scene_img, x, y, color);

            floorX += floorStepX;
            floorY += floorStepY;
            x++;
        }
        y++;
    }
    return (0);
}

int draw_textured_ceiling(t_data *dt)
{
    t_texture texture = dt->map.wall_tile[6].texture;
    int x, y;

    y = dt->view->screen_center_y;

    while (y >= 0)
    {
		float fov_factor = tanf((FIELD_OF_VIEW_DEG * 0.635f) * (M_PI / 180.0f));

		float plane_x = dt->player.plane_x;
		float plane_y = dt->player.plane_y;

        // Calculate ray position relative to camera plane
        float rayDirX0 = dt->player.direction_vector.x + plane_x;
        float rayDirY0 = dt->player.direction_vector.y - plane_y;
        float rayDirX1 = dt->player.direction_vector.x - plane_x;
        float rayDirY1 = dt->player.direction_vector.y + plane_y;

        int p = y - dt->view->screen_center_y;
        float rowDistance = ((0.5f * WINDOW_H) / p) / fov_factor;


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
			// apply_distance_shadow_floor(20, &color);
            img_pix_put(dt->raycasting_scene_img, x, y, color);

            floorX += floorStepX;
            floorY += floorStepY;
            x++;
        }
        y--;
    }
    return (0);
}

