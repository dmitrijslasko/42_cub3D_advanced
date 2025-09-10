/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:39 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 14:15:53 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_default_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->a = 0;
}

void	init_default_texture(t_texture *texture)
{
	texture->xpm_file_pathfile = NULL;
	texture->texture_img = NULL;
	texture->texture_data = NULL;
}

void	init_default_wall_tile(t_wall_tile *wall_tile)
{
	wall_tile->is_color = 0;
	wall_tile->wall_orientation = DEFAULT_WALL;
	init_default_texture(&wall_tile->texture);
	init_default_color(&wall_tile->color);
}

int		init_default_textures(t_map *map)
{
	int i;

	i = 0;
	while (i < NUMBER_TEXTURES)
		init_default_wall_tile(&map->textures[i++]);
	return (EXIT_SUCCESS);
}

bool	init_default_map(t_map *map)
{
	print_separator_default();
	printf("Initiliazing default map... ");
	map->map_data = NULL;
	map->map_size_cols = 0;
	map->map_size_rows = 0;
	init_default_textures(map);
	printf("Done!\n");
	return (EXIT_SUCCESS);
}
