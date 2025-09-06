/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 01:05:01 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_texture_coor(t_data *dt, float screen_x, int *texture_x, \
							float angle_offset)
{
	float	view_ratio;
	float	tex_ratio;

	view_ratio = screen_x / (float)WINDOW_W;
	tex_ratio = fmodf(view_ratio + angle_offset, 1.0f);
	*texture_x = (int)(tex_ratio * dt->sky_image->width);
}

float	calculate_angle_offset(t_data *dt)
{
	float	angle_offset;
	float	angle_rad;

	angle_rad = dt->player.direction_vector_deg * (M_PI / 180.0f);
	angle_offset = fmodf((angle_rad * 6.0f) / (2 * M_PI), 1.0f);
	if (angle_offset < 0)
		angle_offset += 1.0f;
	return (angle_offset);
}

int	calc_texture_start_y(t_data *dt)
{
	int texture_start_y;

	texture_start_y = dt->sky_image->height - dt->view->screen_center_y;
	return (texture_start_y);
}

uint32_t	get_pixel_color_from_img(t_img *tex, int x, int y)
{
	char	*pixel;
	
	pixel = tex->addr + y * tex->line_len + x * (tex->bpp / 8);
	return (*(uint32_t *)pixel);
}

int	ft_max_float(float num1, float num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

int	ft_min_float(float num1, float num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}


int	render_sky(t_data *dt, float angle_offset, int texture_start_y)
{
	t_coor		screen;
	int			texture_x;
	uint32_t	color;
	int			max_sky_y;
	float		wall_height;
	// t_img		*sky_image;

	screen.x = 0;
	// sky_image = dt->map->textures[0].texture.texture_img;
	// printf("%d\n", sky_image->width);
	while (screen.x < WINDOW_W)
	{
		wall_height = ft_min_float(dt->rays[screen.x * CASTED_RAYS_COUNT / WINDOW_W].wall_height, (float)WINDOW_H);
		max_sky_y = dt->view->screen_center_y - (int)wall_height / 2;
		screen.y = 0;
		while (screen.y < max_sky_y)
		{
			ft_texture_coor(dt, screen.x, &texture_x, angle_offset);
			color = get_pixel_color_from_img(dt->sky_image, texture_x, screen.y + texture_start_y);
			img_pix_put(dt->raycasting_scene_img, screen.x, screen.y, color);
			screen.y++;
		}
		screen.x++;
	}
	return (EXIT_SUCCESS);
}

int	draw_sky(t_data *dt)
{
	float	angle_offset;
	int		texture_start_y;

	angle_offset = calculate_angle_offset(dt);
	angle_offset += (dt->time.last_time - dt->time.start_time) * 0.00001f;
	texture_start_y = calc_texture_start_y(dt);

	render_sky(dt, angle_offset, texture_start_y);
	return (EXIT_SUCCESS);
}
