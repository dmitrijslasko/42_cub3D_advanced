/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_mouse_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/09 18:00:13 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_mouse_to_screen_center(t_data *dt)
{
	// mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, WINDOW_W / 2, \
	// 										dt->view->screen_center_y);
	mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, 0, 0);
	mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, WINDOW_W, WINDOW_H);
	return (EXIT_SUCCESS);
}

int	reset_mouse_position(t_data *dt)
{
	int	dx;
	int	dy;
	int	new_x;
	int	new_y;

	dx = dt->mouse.x - WINDOW_W / 2;
	dy = dt->mouse.y - WINDOW_H / 2;
	// if (dt->mouse.suppress_mouse_frames > 0)
	// {
	// 	dt->mouse.suppress_mouse_frames--;
	// 	return (EXIT_SUCCESS);
	// }
	if (abs(dx) > MOUSE_CENTER_TOLERANCE_PX || \
		abs(dy) > MOUSE_CENTER_TOLERANCE_PX)
	{
		new_x = dt->mouse.x;
		new_y = dt->mouse.y;
		if (abs(dx) > MOUSE_CENTER_TOLERANCE_PX)
			new_x = WINDOW_W / 2 + sign(dx) * MOUSE_CENTER_TOLERANCE_PX;
		if (abs(dy) > MOUSE_CENTER_TOLERANCE_PX)
			new_y = WINDOW_H / 2 + sign(dy) * MOUSE_CENTER_TOLERANCE_PX;
		// dt->mouse.suppress_mouse_frames = 1;
		mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, new_x, new_y);
	 	// system("gsettings set org.gnome.desktop.a11y.magnifier mouse-tracking true");
	}
	return (EXIT_SUCCESS);
}
