/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keyboard_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:26 by fvargas           #+#    #+#             */
/*   Updated: 2025/09/08 16:41:44 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress_exit(t_data *dt)
{
	printf("ESC button pressed, closing the window...");
	free_dt(dt);
	printf("Done!\n");
	system("gnome-extensions enable ubuntu-dock@ubuntu.com");
	system("gsettings set org.gnome.shell.extensions.dash-to-dock dock-fixed true");
	system("gsettings set org.gnome.shell.extensions.dash-to-dock autohide false");
	system("gsettings set org.gnome.desktop.a11y.applications screen-magnifier-enabled false");
	system("gsettings set org.gnome.desktop.peripherals.mouse speed 0");

	exit(0);
	return (EXIT_SUCCESS);
}

int	handle_keypress(int keycode, t_data *dt)
{
	if (keycode == ESC_BUTTON)
		keypress_exit(dt);
	else if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 1;
	return (0);
}

int switch_weapon(t_data *dt, int new_weapon)
{
	dt->player.selected_weapon = &dt->weapon[new_weapon];
	dt->weapon_is_animating = 0;
	dt->weapon_current_frame = 0;
	*dt->ambient_light = 10.0f;
	return (EXIT_SUCCESS);
}

int	handle_keyrelease(int keycode, t_data *dt)
{
	if (dt->keys[XK_1])
		switch_weapon(dt, WEAPON_NO_WEAPON);
	if (dt->keys[XK_2])
		switch_weapon(dt, WEAPON_KNIFE);
	if (dt->keys[XK_3])
		switch_weapon(dt, WEAPON_PISTOL);
	if (dt->keys[XK_4])
		switch_weapon(dt, WEAPON_RIFLE);
	if (dt->keys[XK_5])
		switch_weapon(dt, WEAPON_MACHINE_GUN);
	if (dt->keys[XK_7])
	{
		puts("Switching level!");
		print_level_map(dt->map);
		dt->active_level += 1;
		dt->active_level %= NUMBER_OF_LEVELS;
	}
	if (dt->keys[XK_8])
	{
		float prev_value = *dt->ambient_light;
		if (prev_value > 500)
			*dt->ambient_light = 0.0f;
		else
			*dt->ambient_light = 1000.0f;
	}
	if (keycode == XK_Tab)
		toggle_setting(&dt->view->show_minimap);
	if (keycode == XK_F12)
	{
		toggle_setting(&dt->view->show_debug_info);
		toggle_setting(&dt->view->show_targeted_sprite);
	}
	if (keycode == XK_Control_R || keycode == XK_i && dt->player.selected_weapon->type)
		fire_gun(dt);
	else if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 0;
	return (EXIT_SUCCESS);
}

void	setup_keyboard_hooks(t_data *dt)
{
	printf("Setting up keyboard hooks...");

	mlx_hook(dt->win_ptr, KeyPress, KeyPressMask, handle_keypress, dt);
	mlx_hook(dt->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, dt);
	mlx_hook(dt->win_ptr, 17, 0, keypress_exit, dt);

	mlx_do_key_autorepeatoff(dt->mlx_ptr);

	//if (ENABLE_MOUSE)
	mlx_mouse_hide(dt->mlx_ptr, dt->win_ptr);

	printf(" Done!\n");
}
