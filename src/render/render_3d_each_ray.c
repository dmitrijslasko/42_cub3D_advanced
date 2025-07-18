/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_each_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:15 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:58:08 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NOTE DL: For some reason, does not seems to work? :(
void	apply_wall_orientation_shading(t_ray *ray, int *color)
{
	if (ray->wall_orientation == EAST || ray->wall_orientation == WEST)
	{
		apply_shadow(ray, &color, WALL_ORIENTATION_SHADOW_STRENGTH);
		// *color = YELLOW;
	}
}
void	put_pix_img(t_data *dt, t_ray *ray, t_coor *texture, t_coor *coor)
{
	int		color;

	color = get_color_render3d(dt, ray, texture);
	if (ENABLE_SHADERS)
	{
		apply_wall_orientation_shading(ray, &color);
		apply_distance_shadow(ray, &color);
	}
	img_pix_put(dt->raycasting_scene_img, coor->x, coor->y, color);
}

void	render_3d_each_ray(t_data *dt, t_ray *ray, int screen_slice_width)
{
	float	wall_height;
	int		top_y;
	t_coor	coor;
	t_coor	texture;
	size_t	bottom_y;

	texture.x = 0;
	texture.y = 0;
	// NOTE DL: manipulating 1.0f here can be used to simulate water level
	wall_height = 1.0f / ray->corrected_distance_to_wall * SCALING + dt->test_value_3;
	ray->wall_height = (int)wall_height;
	top_y = dt->view->screen_center_y - wall_height - dt->test_value_1 + dt->test_value_1;
	coor.y = ft_max(top_y, 0);
	bottom_y = ft_min(WINDOW_H, dt->view->screen_center_y + wall_height) + dt->test_value_2;
	while (coor.y < bottom_y)
	{
		calc_texture_coor(dt, &texture.y, &ray->corrected_distance_to_wall, coor.y - top_y);
		coor.x = ft_max(ray->id * screen_slice_width, 0);
		while (coor.x < (ray->id + 1) * screen_slice_width && coor.x < WINDOW_W)
		{
			put_pix_img(dt, ray, &texture, &coor);
			coor.x++;
		}
		coor.y++;
	}
}


