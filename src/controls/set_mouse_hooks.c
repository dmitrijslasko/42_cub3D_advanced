/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mouse_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:29 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/24 19:13:44 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fire_gun(t_data *dt)
{
	dt->mouse.lmb_is_pressed = 1;
	dt->mouse.lmb_press_count++;
	if (dt->player.selected_weapon->total_ammo > 0)
	{
		dt->weapon_is_animating = 1;
		system("aplay sounds/shot.wav > /dev/null 2>&1 &");
		dt->player.selected_weapon->total_ammo = ft_max(0, --dt->player.selected_weapon->total_ammo);
		if (dt->targeted_sprite)
			dt->targeted_sprite->current_frame = 1;
	}
	else
		system("aplay sounds/empty-gun.wav &");
	// printf("🖱️  LMB is pressed! Total press count: %zu\n", dt->mouse.lmb_press_count);
	return (EXIT_SUCCESS);
}

// Handle mouse press
// Currently only works for LMB
int	mouse_press(int button, int x, int y, t_data *dt)
{
	(void) x;
	(void) y;
	if (button == MOUSE_LEFT_BUTTON)
		fire_gun(dt);
	return (EXIT_SUCCESS);
}

// Handle mouse release
// Currently only works for LMB
int	mouse_release(int button, int x, int y, t_data *dt)
{
	(void) x;
	(void) y;
	if (button == MOUSE_LEFT_BUTTON)
	{
		dt->mouse.lmb_is_pressed = 0;
		// printf("LMB released!\n");
		// dt->weapon_current_frame = 0;
	}
	return (0);
}

// Handle mouse move
int	mouse_move(int x, int y, t_data *dt)
{
	dt->mouse.prev_x = dt->mouse.x;
	dt->mouse.prev_y = dt->mouse.y;
	dt->mouse.x = x;
	dt->mouse.y = y;

	if (x > dt->mouse.prev_x)
		rotate_player(dt, MOUSE_SENS_ROTATE, -1);
	else if (x < dt->mouse.prev_x)
		rotate_player(dt, MOUSE_SENS_ROTATE, 1);
	if (ENABLE_VERTICAL_LOOK)
	{
		if (y > dt->mouse.prev_y)
			dt->view->screen_center_y = ft_max(
					dt->view->screen_center_y - \
					KEYBOARD_VERTICAL_LOOK_STEP,
					WINDOW_H / 2 - VERTICAL_LOOK_LOCK_DOWN);
		if (y < dt->mouse.prev_y)
			dt->view->screen_center_y = ft_min(
					dt->view->screen_center_y + \
					KEYBOARD_VERTICAL_LOOK_STEP,
					WINDOW_H / 2 + VERTICAL_LOOK_LOCK_UP);
	}
	return (0);
}

void	setup_mouse_hooks(t_data *dt)
{
	printf("Setting up mouse hooks...");
	dt->mouse.lmb_is_pressed = 0;
	dt->mouse.rmb_is_pressed = 0;
	dt->mouse.prev_x = 0;
	dt->mouse.prev_y = 0;
	dt->mouse.x = 0;
	dt->mouse.y = 0;
	dt->player.plane_x = dt->player.direction_vector.y * (FIELD_OF_VIEW_SCALE);
	dt->player.plane_y = dt->player.direction_vector.x * (FIELD_OF_VIEW_SCALE);

	mlx_hook(dt->win_ptr, 4, 1L << 2, mouse_press, dt);
	mlx_hook(dt->win_ptr, 5, 1L << 3, mouse_release, dt);
	mlx_hook(dt->win_ptr, 6, 1L << 6, mouse_move, dt);
	set_mouse_to_screen_center(dt);
	reset_mouse_position(dt);
	printf(" Done!\n");
}
