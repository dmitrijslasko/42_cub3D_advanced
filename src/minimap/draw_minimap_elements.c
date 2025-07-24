/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:49 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 18:35:19 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_minimap_wall_cell(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor	coor;

	set_coor_values(&coor, curr_col * MINIMAP_GRID_SIZE,
		curr_row * MINIMAP_GRID_SIZE);
	draw_square_from_top_left(dt->minimap_base_img,
		coor,
		MINIMAP_GRID_SIZE,
		MINIMAP_WALL_CELL_COLOR);
	return (EXIT_SUCCESS);
}

int	draw_minimap_thin_wall_vertical(t_data *dt, size_t curr_col, \
															size_t curr_row)
{
	t_coor	top_left;
	t_coor	bottom_right;

	top_left.x = curr_col * MINIMAP_GRID_SIZE;
	top_left.y = curr_row * MINIMAP_GRID_SIZE;
	bottom_right.x = top_left.x + 10;
	bottom_right.y = (curr_row + 1) * MINIMAP_GRID_SIZE;
	draw_rectangle(dt->minimap_base_img, top_left, bottom_right,
		MINIMAP_THIN_WALL_COLOR);
	return (EXIT_SUCCESS);
}

int	draw_minimap_door_vertical(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor	top_left;
	t_coor	bottom_right;

	top_left.x = (curr_col + 0.5f) * MINIMAP_GRID_SIZE;
	top_left.y = curr_row * MINIMAP_GRID_SIZE;
	bottom_right.x = top_left.x + MINIMAP_DOOR_THICKNESS_PX;
	bottom_right.y = (curr_row + 1) * MINIMAP_GRID_SIZE;
	draw_rectangle(dt->minimap_base_img, top_left, bottom_right,
		MINIMAP_DOOR_COLOR);
	return (EXIT_SUCCESS);
}

int	draw_minimap_door_horizontal(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor	top_left;
	t_coor	bottom_right;

	top_left.x = curr_col * MINIMAP_GRID_SIZE;
	top_left.y = (curr_row  + 0.5f) * MINIMAP_GRID_SIZE;
	bottom_right.x = (curr_col + 1) * MINIMAP_GRID_SIZE;
	bottom_right.y = top_left.y + MINIMAP_DOOR_THICKNESS_PX;
	draw_rectangle(dt->minimap_base_img, top_left, bottom_right,
		MINIMAP_DOOR_COLOR);
	return (EXIT_SUCCESS);
}

int	draw_minimap_sprite(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor	center;

	center.x = (curr_col + 0.5f) * MINIMAP_GRID_SIZE;
	center.y = (curr_row + 0.5f) * MINIMAP_GRID_SIZE;
	draw_circle(dt->minimap_base_img, &center, 10, MINIMAP_SPRITE_COLOR);
	return (EXIT_SUCCESS);
}
