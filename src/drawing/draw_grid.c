/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:50 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:51 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_grid(t_data *dt)
{
	int	col_px;
	int	row_px;

	t_map	*active_map;

	active_map = dt->map;

	row_px = 0;
	while (row_px <= active_map->map_size_rows * MINIMAP_GRID_SIZE + 1)
	{
		col_px = 0;
		while (col_px <= active_map->map_size_cols * MINIMAP_GRID_SIZE + 1)
		{
			if (col_px % MINIMAP_GRID_SIZE == 0 || \
						row_px % MINIMAP_GRID_SIZE == 0)
				img_pix_put(dt->minimap_base_img, col_px,
					row_px, MINIMAP_GRID_COLOR);
			col_px++;
		}
		row_px++;
	}
}
