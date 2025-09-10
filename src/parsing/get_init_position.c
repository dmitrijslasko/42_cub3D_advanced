/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init_player_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:47 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:48 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_and_set_player_position(t_player *player, size_t col, size_t row, char c)
{
	float	dir_x;
	float	dir_y;

	if (c == 'N')
	{
		dir_x = 0;
		dir_y = -1;
		player->orientation = 270.0f;
	}
	else if (c == 'S')
	{
		dir_x = 0;
		dir_y = 1;
		player->orientation = 90.0f;
	}
	else if (c == 'E')
	{
		dir_x = 1;
		dir_y = 0;
		player->orientation = 0.0f;
	}
	else
	{
		dir_x = -1;
		dir_y = 0;
		player->orientation = 180.0f;
	}
	set_values_x_y(&player->orientation_vector, dir_x, dir_y);
	printf("%f %f\n", col+0.5, row+0.5);
	set_values_x_y(&player->pos, col + 0.5, row + 0.5);
}

void	get_init_player_position(t_map *map, t_player *player)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < map->map_size_rows)
	{
		col = 0;
		while (col < map->map_size_cols)
		{
			c = map->map_data[row][col].map_char;
			if (ft_strchr(PLAYER_SPAWN_POINT_TYPES, c))
			{
				find_and_set_player_position(player, col, row, c);
				return ;
			}
			col++;
		}
		row++;
	}
}
