/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_render3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/18 17:28:41 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture *handle_door(int *tex_index, t_ray *ray, t_coor *tex_coor, t_data *dt)
{
	float		side;
	t_texture	*texture;
	int			index;

	index = get_lookup_table_index_cell_type(ray->cell_type);

	if (index == -1)
		return (NULL);

	if (g_texture_lookup[index].map_char == NULL)
		return (NULL);
	
	if (ft_strchr(VERTICAL_DOOR_TYPES, ray->hit_content))
		side = ray->vector.x;
	else if (ft_strchr(HORIZONTAL_DOOR_TYPES, ray->hit_content))
		side = -ray->vector.y;
	else
		return (NULL);

	texture = &dt->map->textures[ray->cell_type].texture;

	if (side > 0)
		*tex_index = texture->width * (tex_coor->y + (ray->percentage_of_image - ray->door->open_progress));
	else
		*tex_index = texture->width * (tex_coor->y + (1.0f - ray->percentage_of_image - ray->door->open_progress));

	return texture;
}

int	get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor)
{
	int			color;
	int			tex_index;
	int			side_texture_index;
	t_texture  *texture = NULL;

	// handle door
	if (ft_strchr(DOOR_TYPES, ray->hit_content))
	{
		texture = handle_door(&tex_index, ray, tex_coor, dt);
		if (!texture)
			texture = &dt->map->textures[ray->cell_type].texture;
	}
	// handle door neighbours
	else if (ray->hit_side == 'y' && ray->door && ray->door->orientation == 1 ||
		ray->hit_side == 'x' && ray->door && ray->door->orientation == 0)
	{
		side_texture_index = ray->door->side_texture_index;
		texture = &dt->map->textures[side_texture_index].texture;
		tex_coor->x = texture->width * ray->percentage_of_image;
		tex_index = texture->width * tex_coor->y + tex_coor->x;
	}
	// handle everything else
	else
	{
		texture = &dt->map->textures[ray->cell_type].texture;
		tex_coor->x = texture->width * ray->percentage_of_image;
		tex_index = texture->width * tex_coor->y + tex_coor->x;
	}
	color = texture->texture_data[tex_index];

	return (color);
}
