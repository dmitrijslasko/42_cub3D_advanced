/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_render3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 18:54:10 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_door(int *tex_index, t_ray *ray, t_texture *texture, t_coor *tex_coor, t_data *dt)
{
	float 		side;

	if (ray->cell_type == DOOR_VERTICAL_1)
		side = ray->vector.x;
	else if (ray->cell_type == DOOR_HORIZONTAL_1)
		side = -ray->vector.y;
	*texture = dt->map.textures[DOOR_1].texture;
	if (side > 0)
		*tex_index = (texture->width * (tex_coor->y + (ray->percentage_of_image - ray->door->open_progress)));
	else
		*tex_index = (texture->width * (tex_coor->y + (1.0f - ray->percentage_of_image - ray->door->open_progress)));
}

int	get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor)
{
	int			color;
	int			tex_index;
	t_texture	texture;


	texture = dt->map.textures[ray->cell_type].texture;
	tex_coor->x = (texture.width * ray->percentage_of_image);
	tex_index = texture.width * tex_coor->y + tex_coor->x;
	// TODO DL: ugly af, has to be redone... check if there is a way to use ft_strchr
	if (ray->cell_type == DOOR_VERTICAL_1 || ray->cell_type == DOOR_HORIZONTAL_1 || ray->cell_type == DOOR_2)
		handle_door(&tex_index, ray, &texture, tex_coor, dt);
	color = texture.texture_data[tex_index];
	if (ENABLE_SHADERS)
		apply_distance_shadow(ray, &color);
	return (color);
}
