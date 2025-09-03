/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 17:08:40 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_ceiling(t_data *dt)
{
	int			color;
	t_coor		top_left;
	t_coor		bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, WINDOW_W, dt->view->screen_center_y);
	color = create_color_rgb(dt->map->textures[CEILING].color.r, \
							dt->map->textures[CEILING].color.g, \
							dt->map->textures[CEILING].color.b);
	draw_rectangle(dt->raycasting_scene_img, top_left, bottom_right, color);
	return (EXIT_SUCCESS);
}

int	draw_floor(t_data *dt)
{
	int		color;
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, dt->view->screen_center_y);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H);

	color = create_color_rgb(	dt->map->textures[FLOOR].color.r, \
								dt->map->textures[FLOOR].color.g,
								dt->map->textures[FLOOR].color.b);
	
								
	color = DARKGREY;
	apply_distance_shadow_distance(*dt->ambient_light, &color);
	draw_rectangle(dt->raycasting_scene_img, top_left, bottom_right, color);

	return (EXIT_SUCCESS);
}

int	apply_distance_shadow_distance(int distance, int *color)
{
	float	shade;
	int		r;
	int		g;
	int		b;

	if (*color == BLACK)
		return (0);
	distance = ft_max(0, distance);
	shade = fmax(0.1f, 1.0f / (1.0f + distance * 0.01f * DISTANCE_SHADOW_STRENGTH));

	r = ((*color >> 16) & 0xFF) * shade;
	g = ((*color >> 8) & 0xFF) * shade;
	b = ((*color >> 0) & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | (b << 0);
	return (EXIT_SUCCESS);
}

