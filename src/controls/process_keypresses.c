/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keyboard_keypresses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:00 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 20:30:13 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	process_vertical_look(t_data *dt)
{
	if (!ENABLE_VERTICAL_LOOK)
		return ;
	if (dt->keys[XK_Up])
	{
		dt->view->screen_center_y = ft_min(
				dt->view->screen_center_y + KEYBOARD_VERTICAL_LOOK_STEP,
				WINDOW_H / 2 + VERTICAL_LOOK_LOCK_UP);
	}
	if (dt->keys[XK_Down])
	{
		// dt->has_changed = 1;
		dt->view->screen_center_y = ft_max(
				dt->view->screen_center_y - KEYBOARD_VERTICAL_LOOK_STEP,
				WINDOW_H / 2 - VERTICAL_LOOK_LOCK_DOWN);
	}
}

void	open_close_door(t_data *dt, int dir)
{
	t_coor	cell_ahead;
	t_door	*door;

	cell_ahead = get_cell_ahead(dt);
	if (ft_strchr(DOOR_TYPES, get_cell_type(dt->map, &cell_ahead)))
	{
		door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
		if (dir == 1)
		{
			door->open_progress = fmax(0.0f, door->open_progress - door->speed);
			door->opening_finish_time = dt->runtime_stats.last_time;
		}
		else
			door->open_progress = fmin(1.0f, door->open_progress + door->speed);
	}
}

void	open_close_door2(t_data *dt)
{
	t_coor	cell_ahead;
	t_door	*door;

	cell_ahead = get_cell_ahead(dt);
	if (ft_strchr(DOOR_TYPES, get_cell_type(dt->map, &cell_ahead)))
	{
		door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
		if (door->open_progress == 0.0f)
			system(SLIDING_DOOR_SYSTEM_CALL);
		door->is_opening = 1;
	}
}

static void	process_door(t_data *dt)
{
	if (dt->keys[XK_bracketleft])
	{
		open_close_door(dt, -1);
	}
	if (dt->keys[XK_bracketright])
		open_close_door(dt, 1);
	if (dt->keys[XK_e])
		open_close_door2(dt);
}

void	process_keyboard_keypresses(t_data *dt)
{
	int is_moving_now = 0;

	if (dt->keys[XK_w])
	{
		move_forward_backward(dt, 1);
		is_moving_now = 1;
	}
	else if (dt->keys[XK_s])
	{
		move_forward_backward(dt, -1);
		is_moving_now = 1;
	}

	if (dt->keys[XK_a])
	{
		move_sideways(dt, -1);
		is_moving_now = 1;
	}
	else if (dt->keys[XK_d])
	{
		move_sideways(dt, 1);
		is_moving_now = 1;
	}
	dt->player.is_moving = is_moving_now;
	// if (dt->keys[XK_f])
	// {
	// 	// dt->test_value_1 -= 10.0f;
	// 	printf("%f\n", dt->test_value_1);
	// }
	// if (dt->keys[XK_g])
	// {
	// 	dt->test_value_1 += 0.001f;
	// 	printf("%f\n", dt->test_value_1);
	// }
	if (dt->keys[XK_h])
	{
		dt->test_value_1 -= 1;
		dt->test_value_3 -= 0.05f;
		printf("%f\n", dt->test_value_1);
	}
	if (dt->keys[XK_j])
	{
		dt->test_value_1 += 1;
		dt->test_value_3 += 0.05f;
		printf("%d\n", dt->test_value_1);
	}
	// if (dt->keys[XK_n])
	// {
	// 	dt->test_value_2 -= 1;
	// 	printf("%d\n", dt->test_value_2);
	// }
	if (dt->keys[XK_m])
	{
		print_level_map(&dt->levels[dt->active_level].map);
		printf("COLS: %zu\n", dt->levels[dt->active_level].map.map_size_cols);
		printf("ROWS: %zu\n", dt->levels[dt->active_level].map.map_size_rows);
	}
	if (dt->keys[XK_9])
	{
		*dt->ambient_light = fmin(1000.0f, *dt->ambient_light * 1.1f);
		// printf("Ambient light: %.2f\n", *dt->ambient_light);
	}
	if (dt->keys[XK_0])
	{
		*dt->ambient_light = fmax(1.0f, *dt->ambient_light / 1.1f);
		// printf("Ambient light: %.2f\n", *dt->ambient_light);
	}
	
	// turn left
	if (dt->keys[XK_Left])
		rotate_player(dt, KEYBOARD_PLAYER_ROTATION_STEP, 1);
	// turn right
	if (dt->keys[XK_Right])
		rotate_player(dt, KEYBOARD_PLAYER_ROTATION_STEP, -1);
	if (dt->keys[XK_Shift_L] && dt->player.is_moving)
	{
		dt->player.move_speed_multiplier = MOVE_SPEED_MULTIPLIER_FAST;
		dt->jump_strength = 0.06f;
	}
	else
	{
		dt->player.move_speed_multiplier = 1.0f; 
		dt->jump_strength = 0.06f;
	}

	// jump
	if (dt->keys[XK_space])
	{
		if (dt->jump_dir == 0)
			dt->jump_dir = 1;
	}
	// crouch
	else if (dt->keys[XK_c] && dt->jump_dir == 0)
	{
		dt->crouch = 1;
		dt->player.move_speed_multiplier = 0.5f;
	}
	else if (dt->jump_dir == 0)
	{
		dt->z_offset = 0.0f;
	}
	process_door(dt);
	process_vertical_look(dt);
}
