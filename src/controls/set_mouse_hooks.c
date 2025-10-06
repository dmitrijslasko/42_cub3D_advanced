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

int play_weapon_sound(t_data *dt)
{
	t_weapon active_weapon;
	char	*sound;

	active_weapon = *dt->player.selected_weapon;
	if (active_weapon.type == WEAPON_KNIFE)
		sound = KNIFE_ATTACK_SOUND;
	if (active_weapon.total_ammo == 0)
		sound = EMPTY_GUN_SOUND;
	else if (active_weapon.type == WEAPON_PISTOL)
		sound = PISTOL_ATTACK_SOUND;
	else if (active_weapon.type == WEAPON_RIFLE)
		sound = RIFLE_ATTACK_SOUND;
	else if (active_weapon.type == WEAPON_MACHINE_GUN)
		sound = MACHINE_GUN_ATTACK_SOUND;
	play_sound(sound);
	return (EXIT_SUCCESS);
}
int	fire_gun(t_data *dt)
{
	t_sprite *sprite;

	sprite = &dt->sprites;

	// dt->mouse.lmb_is_pressed = 1;
	// dt->mouse.lmb_press_count++;

	dt->weapon_is_animating = 0;
	dt->weapon_current_frame = 0;
	dt->weapon_is_animating = 1;
	play_weapon_sound(dt);

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
		dt->mouse.lmb_is_pressed = 0;
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

	mlx_hook(dt->win_ptr, 4, 1L << 2, mouse_press, dt);
	mlx_hook(dt->win_ptr, 5, 1L << 3, mouse_release, dt);
	mlx_hook(dt->win_ptr, 6, 1L << 6, mouse_move, dt);

	set_mouse_to_screen_center(dt);
	reset_mouse_position(dt);

	printf(" Done!\n");
}
