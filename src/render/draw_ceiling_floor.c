/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:14:16 by dmlasko          ###   ########.fr       */
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

int	draw_textured_floor(t_data *dt)
{
	t_texture texture = dt->map.door.texture;
	int x;
	int y;
	uint32_t color;
	
	y = dt->view->screen_center_y;
	
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			color = texture.texture_data[(64 * y + x) % (64 * 64)];
			img_pix_put(dt->raycasting_scene_img, x, y, color);
			x++;
		}
		y++;
	}

	// int screen_center_y = dt->view->screen_center_y;
	// int y;

	// y = screen_center_y;
	// while (y < WINDOW_H)
	// {
	// 	// Distance from player to the row
	// 	// float row_distance = (float)dt->view->z_plane_height / (y - screen_center_y);
	// 	float row_distance = 0.5f / (y - screen_center_y);

	// 	// Calculate left and right ray directions (for the row)
	// 	float plane_x = dt->player.direction_vector.x * 0.66;
	// 	float plane_y = dt->player.direction_vector.y * 0.66;

	// 	float ray_dir_x0 = dt->player.direction_vector.x - plane_x;
	// 	float ray_dir_y0 = dt->player.direction_vector.x - plane_y;
	// 	float ray_dir_x1 = dt->player.direction_vector.x + plane_x;
	// 	float ray_dir_y1 = dt->player.direction_vector.x + plane_y;

	// 	// Step in world space per screen pixel
	// 	float step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / WINDOW_W;
	// 	float step_y = row_distance * (ray_dir_y1 - ray_dir_y0) / WINDOW_W;

	// 	// Start world position
	// 	float floor_x = dt->player.pos.x + row_distance * ray_dir_x0;
	// 	float floor_y = dt->player.pos.y + row_distance * ray_dir_y0;

	// 	for (int x = 0; x < WINDOW_W; x++)
	// 	{
	// 		int tx = (int)(texture.width * (floor_x - (int)floor_x)) & (texture.width - 1);
	// 		int ty = (int)(texture.height * (floor_y - (int)floor_y)) & (texture.height - 1);

	// 		uint32_t color = texture.texture_data[ty * texture.width + tx];
	// 		color = BLUE;
		
	// 		floor_x += step_x;
	// 		floor_y += step_y;
	// 	}
	// 	y++;
	// }
	// return (EXIT_SUCCESS);
}

