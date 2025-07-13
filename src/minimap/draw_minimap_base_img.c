/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_base_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:46 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:47 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_draw_func)(t_data *, size_t, size_t);

t_draw_func	get_draw_func_for_tile(char tile)
{
	if (ft_strchr(VERTICAL_WALL_TYPES, tile))
		return (draw_minimap_THIN_WALL_VERTICAL_1);
	if (ft_strchr(VERTICAL_DOOR_TYPES, tile))
		return (draw_minimap_door_vertical);
	if (ft_strchr(WALL_TYPES, tile))
		return (draw_minimap_wall_cell);
	if (ft_strchr(SPRITE_TYPES, tile))
		return (draw_minimap_sprite);
	return (NULL);
}

int	draw_minimap_elements(t_data *dt)
{
	int			row;
	int			col;
	char		tile;
	t_draw_func	draw;

	row = 0;
	while (row < dt->map.map_size_rows)
	{
		col = 0;
		while (col < dt->map.map_size_cols)
		{
			tile = dt->map.map_data[row][col];
			draw = get_draw_func_for_tile(tile);
			if (draw)
				draw(dt, col, row);
			col++;
		}
		row++;
	}
	return (EXIT_SUCCESS);
}

int	draw_minimap_base_img(t_data *dt)
{
	t_coor	top_left;
	t_coor	bottom_right;

	printf(TXT_YELLOW ">>> PREPARING MINIMAP BASE MAP\n" TXT_RESET);
	dt->minimap_base_img = protected_malloc(sizeof(t_img), dt);
	setup_img(dt, dt->minimap_base_img,
		dt->map.map_size_cols * MINIMAP_GRID_SIZE,
		dt->map.map_size_rows * MINIMAP_GRID_SIZE);
	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, dt->minimap_base_img->width,
		dt->minimap_base_img->height);
	draw_rectangle(dt->minimap_base_img, top_left, bottom_right,
		MINIMAP_BACKGROUND_COLOR);
	draw_minimap_elements(dt);
	if (MINIMAP_GRID_ENABLE)
		draw_minimap_grid(dt);
	printf("Finished rendering the minimap base image!\n");
	return (EXIT_SUCCESS);
}
