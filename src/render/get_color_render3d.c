/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_render3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:48:24 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_door(int *tex_index, t_ray *ray, t_texture *texture, t_coor *tex_coor, t_data *dt)
{
	float 		side;
	int			index;

	index = get_lookup_table_index_cell_type(ray->cell_type);
	if (index == -1)
		return ;
	if (ft_strchr(VERTICAL_DOOR_TYPES, g_texture_lookup[index].map_char))
		side = ray->vector.x;
	if (ft_strchr(HORIZONTAL_DOOR_TYPES, g_texture_lookup[index].map_char))
		side = -ray->vector.y;
	*texture = dt->map.textures[ray->cell_type].texture;
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
	int			index;
	int			is_door_side;

	texture = dt->map.textures[ray->cell_type].texture;
	dt->map.map_data[0][7].is_near_door = 1;
	dt->map.map_data[3][7].is_near_door = 1;

	dt->map.map_data[3][11].is_near_door = 1;
	dt->map.map_data[3][14].is_near_door = 1;
	is_door_side = get_cell_by_coordinates(&dt->map, (size_t)ray->wall_hit.y, (size_t)ray->wall_hit.x).is_near_door;
	if (is_door_side && ray->hit_side == 'y')
		texture = dt->map.textures[DOOR_1_SIDES].texture;
	tex_coor->x = (texture.width * ray->percentage_of_image);
	tex_index = texture.width * tex_coor->y + tex_coor->x;
	index = get_lookup_table_index_cell_type(ray->cell_type);
	if (ft_strchr(DOOR_TYPES, g_texture_lookup[index].map_char))
		handle_door(&tex_index, ray, &texture, tex_coor, dt);
	color = texture.texture_data[tex_index];
	if (ENABLE_SHADERS)
		apply_distance_shadow(ray, &color);
	return (color);
}
