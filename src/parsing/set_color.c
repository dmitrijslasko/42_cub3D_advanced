/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:16 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:43:08 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_color(t_color *color, int num_color, int count)
{
	if (count == 1)
		color->r = num_color;
	else if (count == 2)
		color->g = num_color;
	else
		color->b = num_color;
}

bool	get_color(t_color *color, char **color_arr)
{
	char	**array;
	int		count;
	size_t	i;
	size_t	j;

	i = 0;
	count = 1;
	while (color_arr[i])
	{
		j = 0;
		array = ft_split(color_arr[i++], ',');
		while (array[j])
		{
			if (!check_only_number(array[j]) || count > 3)
				return (free_array_return(array, 1));
			add_color(color, ft_atoi(array[j++]), count++);
		}
		free_array(array);
	}
	return (0);
}

bool	set_color(char *identifier, char **color, t_map *map)
{
	t_wall_orientation	wall_orientation;

	wall_orientation = check_valid_texture_identifier(identifier);
	if (map->textures[wall_orientation].wall_orientation != DEFAULT_WALL)
		return (error_msg("Error: set color: duplicated wall/door/floor.", 1));
	map->textures[wall_orientation].wall_orientation = wall_orientation;
	map->textures[wall_orientation].is_color = true;
	if (get_color(&map->textures[wall_orientation].color, color))
		return (error_message2("Error: Format/color of ", identifier, 1));
	return (0);
}
