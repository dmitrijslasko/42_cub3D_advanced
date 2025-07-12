/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position_is_walkable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:23 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:15:17 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO DL: This currently only works with vertical cells / movement
t_coor	get_cell_ahead(t_data *dt)
{
	t_coor	player_pos;
	t_coor	cell_ahead;
	t_coor	step;

	player_pos.x = (int) dt->player.pos.x;
	player_pos.y = (int) dt->player.pos.y;
	set_step(&step, &dt->player.direction_vector);
	if (fabs(dt->player.direction_vector.x) > fabs(dt->player.direction_vector.y))
	{
		cell_ahead.x = player_pos.x + step.x;
		cell_ahead.y = player_pos.y + 0;
	}
	else
	{
		cell_ahead.x = player_pos.x + 0;
		cell_ahead.y = player_pos.y + step.y;
	}
	return (cell_ahead);
}

static int	handle_wall(t_data *dt, float *new_x, float *new_y)
{
	t_coor	min;
	t_coor	max;

	min.x = (int)(*new_x - MIN_DISTANCE_TO_WALL);
	max.x = (int)(*new_x + MIN_DISTANCE_TO_WALL);
	min.y = (int)(*new_y - MIN_DISTANCE_TO_WALL);
	max.y = (int)(*new_y + MIN_DISTANCE_TO_WALL);
	if (ft_strchr(WALL_TYPES, dt->map.map_data[min.y][min.x]) ||
	ft_strchr(WALL_TYPES, dt->map.map_data[min.y][max.x]) ||
	ft_strchr(WALL_TYPES, dt->map.map_data[max.y][min.x]) ||
	ft_strchr(WALL_TYPES, dt->map.map_data[max.y][max.x]))
		return (0);
	return (1);
}

//static int	handle_door(t_data *dt, t_coor min, t_coor max)
//{
//	t_coor	cell_ahead;
//	t_door	*door;

//	cell_ahead = get_cell_ahead(dt);
//	dt->player.cell_type_ahead = get_cell_type(&dt->map, &cell_ahead);
//	if (ft_strchr("|", dt->map.map_data[min.y][min.x]) ||
//		ft_strchr("|", dt->map.map_data[min.y][max.x]) ||
//		ft_strchr("|", dt->map.map_data[max.y][min.x]) ||
//		ft_strchr("|", dt->map.map_data[max.y][max.x]))
//	{
//		door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
//		if (door && door->open_progress < DOOR_OPEN_VALUE)
//			return (0);
//	}
//	return (1);
//}

static int	handle_door2(t_data *dt, float *new_x, float *new_y)
{
	t_coor	min;
	t_coor	max;
	t_coor	new_pos;
	t_door	*door;

	min.x = (int)(*new_x - MIN_DISTANCE_TO_WALL);
	max.x = (int)(*new_x + MIN_DISTANCE_TO_WALL);
	min.y = (int)(*new_y - MIN_DISTANCE_TO_WALL);
	max.y = (int)(*new_y + MIN_DISTANCE_TO_WALL);
	set_coor_values(&new_pos, (int)*new_x, (int)*new_y);
	door = find_door_at(dt, new_pos.x, new_pos.y);
	if (ft_strchr(DOOR_TYPES, dt->map.map_data[min.y][min.x]) ||
	ft_strchr(DOOR_TYPES, dt->map.map_data[min.y][max.x]) ||
	ft_strchr(DOOR_TYPES, dt->map.map_data[max.y][min.x]) ||
	ft_strchr(DOOR_TYPES, dt->map.map_data[max.y][max.x]))
	{
		if (door && door->open_progress < DOOR_OPEN_VALUE)
			return (0);
	}
	return (1);
}

// TODO DL: this can be replaced by an already existing function,
// 			bool check_hit_wall(t_coor coord, t_map map)?
// TODO DL: unoptimal placement for the show_door_open_message
int	map_position_is_walkable(t_data *dt, float *new_x, float *new_y)
{
	if (!handle_wall(dt, new_x, new_y))
		return (0);
	if (!handle_door2(dt, new_x, new_y))
		return (0);
	return (1);
}
