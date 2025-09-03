/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_debug_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:33:06 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 18:44:00 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_cell_info(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	char	str[2];
	size_t	i;
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	if (CASTED_RAYS_COUNT == 1)
		i = 0;
	else
		i = CASTED_RAYS_COUNT / 2;
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].wall_hit.x);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Cell hit point X:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].wall_hit.y);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Cell hit point Y:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%d", dt->rays[i].hit_cell->is_near_door);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_2, "Is near door:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].percentage_of_image);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Percentage of image:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	str[0] = dt->player.cell_type_ahead;
	str[1] = '\0';
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Cell ahead:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, str);
}

void	print_door_hit_stats(t_data *dt, void *mlx, void *win, int *y)
{
	size_t	i;
	char	buffer[32];
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	if (CASTED_RAYS_COUNT == 1)
		i = 0;
	else
		i = CASTED_RAYS_COUNT / 2;
	if (dt->rays[i].door && dt->door_count > 0 && dt->rays[i].door_hit_coor.x)
	{
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Door ID:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(dt->rays[i].door->id));
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Door side texture:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(dt->rays[i].door->side_texture_index));
		snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].door_hit_coor.x);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Door hit point X:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
		snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].door_hit_coor.y);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Door hit point Y:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
		snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].distance_to_door);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Distance to door:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
		snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].door->open_progress);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Door open progress:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	}
}

void	print_time_stats(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	snprintf(buffer, sizeof(buffer), "%ld", dt->time.last_time);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Current time:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%ld",
		(dt->time.last_time - dt->time.start_time) / 1000);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Elapsed time (s):");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_2, "Frames drawn:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_2, ft_itoa(dt->frames_drawn_count));
}

void	print_plane_stats(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	snprintf(buffer, sizeof(buffer), "%.4f", dt->player.plane_x);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Plane X:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	f = mlx_string_put;
	snprintf(buffer, sizeof(buffer), "%.4f", dt->player.plane_y);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Plane Y:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
}

void	show_debug_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	int		(*f)(void*, void*, int, int, int, char*);

	if (!dt->view->show_debug_info)
		return ;
	f = mlx_string_put;
	// y = DBG_FIELD_OFFST_Y;
	y = 0;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	// print_window_info(dt, mlx, win, &y);
	// print_plane_stats(dt, mlx, win, &y);
	print_player_position(dt, mlx, win, &y);
	print_obstacle_info(dt, mlx, win, &y);
	print_cell_info(dt, mlx, win, &y);
	print_door_hit_stats(dt, mlx, win, &y);
	f(mlx, win, DBG_1_X, y += DBG_MN_NL_2, UI_CLR_1, "LMB presses:");
	f(mlx, win, DBG_2_X, y, UI_CLR_1, ft_itoa(dt->mouse.lmb_press_count));
	print_time_stats(dt, mlx, win, &y);
	print_enemy_info(dt, mlx, win, &y);
}

void	show_player_info(t_data *dt)
{
	int		x;
	void	*mlx;
	void	*win;
	//int		(*f)(void*, void*, int, int, int, char*);

	x = 20;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, x, WINDOW_H - 20, GOLD, "Health: ");
	mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, ft_itoa(dt->player.health_level));

	mlx_string_put(mlx, win, x += 100, WINDOW_H - 20, GOLD, "Weapon: ");
	mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, dt->player.selected_weapon->description);
	//mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, ft_itoa(dt->weapon->type));

	mlx_string_put(mlx, win, x += 100, WINDOW_H - 20, GOLD, "Ammo: ");
	mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, ft_itoa(dt->player.selected_weapon->total_ammo));

	mlx_string_put(mlx, win, x += 100, WINDOW_H - 20, GOLD, "Target: ");
	
	// char	buffer[32];
	// snprintf(buffer, sizeof(buffer), "%.2f", dt->sprites[30].orientation_to_player);
	// mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, buffer);

	// mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, ft_itoa(dt->sprites[30].current_frame));

	if (dt->targeted_sprite)
		mlx_string_put(mlx, win, x += 65, WINDOW_H - 20, GOLD, ft_itoa(dt->targeted_sprite->id));
}

void	show_level_info(t_data *dt)
{
	void	*mlx;
	void	*win;

	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	size_t y = 20;

	mlx_string_put(mlx, win, 15, y, GOLD, "Active level: ");
	mlx_string_put(mlx, win, 100, y, GOLD, ft_itoa(dt->active_level));

	mlx_string_put(mlx, win, 15, y += DBG_MN_NL_2, GOLD, "Level score: ");
	mlx_string_put(mlx, win, 100, y, GOLD, ft_itoa(dt->levels[dt->active_level].level_score));

	mlx_string_put(mlx, win, 15, y += DBG_MN_NL, GOLD, "Total score: ");
	mlx_string_put(mlx, win, 100, y, GOLD, ft_itoa(dt->gamescore));

	mlx_string_put(mlx, win, 15, y += DBG_MN_NL, GOLD, "Collected: ");
	mlx_string_put(mlx, win, 100, y, GOLD, ft_itoa(dt->levels[dt->active_level].consumables_collected));

	mlx_string_put(mlx, win, 15, y += DBG_MN_NL_2, GOLD, "Available: ");
	mlx_string_put(mlx, win, 100, y, GOLD, ft_itoa(dt->levels[dt->active_level].level_consumable_count - dt->levels[dt->active_level].consumables_collected));

	mlx_string_put(mlx, win, 15, y += DBG_MN_NL_2, GOLD, "Combo: ");
	
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%.2f", dt->levels[dt->active_level].score_combo);
	mlx_string_put(mlx, win, 100, y, GOLD, buffer);

}