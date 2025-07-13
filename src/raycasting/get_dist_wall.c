/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:45 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:34:21 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cell_type(t_data *dt, t_ray *ray, t_coor *map_coor)
{
	char	cell_type;

	cell_type = get_cell_type(&dt->map, map_coor);
	if (cell_type == '1')
		ray->cell_type = WALL_1;
	else if (cell_type == '2')
		ray->cell_type = WALL_2;
	else if (cell_type == '3')
		ray->cell_type = WALL_3;
	else if (cell_type == '4')
		ray->cell_type = WALL_4;
	else if (cell_type == '5')
		ray->cell_type = WALL_5;
	else if (cell_type == '6')
		ray->cell_type = WALL_6;
	else if (cell_type == '7')
		ray->cell_type = WALL_7;
	else if (cell_type == '8')
		ray->cell_type = WALL_8;
	else if (cell_type == '9')
		ray->cell_type = WALL_9;
	else if (cell_type == '|')
		ray->cell_type = DOOR_VERTICAL_1;
	else if (cell_type == '*')
		ray->cell_type = DOOR_VERTICAL_1;
	else if (cell_type == '-')
		ray->cell_type = DOOR_HORIZONTAL_1;
	else if (cell_type == 'v')
		ray->cell_type = THIN_WALL_VERTICAL_1;
	else if (cell_type == 'h')
		ray->cell_type = THIN_WALL_HORIZONTAL_1;
	else
		ray->cell_type = 0;
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
