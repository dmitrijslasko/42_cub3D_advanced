/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:45 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:50:34 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cell_type(t_data *dt, t_ray *ray, t_coor *map_coor)
{
	char	map_cell_char;
	int		cell_type;
	size_t	i;

	map_cell_char = get_cell_type(dt->map, map_coor);
	cell_type = 0;
	i = 0;
	while (g_texture_lookup[i].mapfile_key)
	{
		if (g_texture_lookup[i].map_char && ft_strchr(g_texture_lookup[i].map_char, map_cell_char))
		{
			ray->hit_content = map_cell_char;
			cell_type = g_texture_lookup[i].texture_type;
			break ;
		}
		i++;
	}
	ray->cell_type = cell_type;
}

void	update_ray_distance_to_cell_edge(t_data *dt, t_ray *ray,
	t_coor *map_coor)
{
	t_coor	step;
	float	distance;

	set_step(&step, &ray->vector);
	distance = 0.0f;
	if (ray->hit_side == 'x')
	{
		distance = ((float)(map_coor->x - dt->player.pos.x + \
										(1 - step.x) / 2.0f)) / ray->vector.x;
	}
	else if (ray->hit_side == 'y')
	{
		distance = ((float)(map_coor->y - dt->player.pos.y + \
										(1 - step.y) / 2.0f)) / ray->vector.y;
	}
	ray->distance_to_wall = fabsf(distance);
}
