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
	t_texture 	door_texture;

	index = get_lookup_table_index_cell_type(ray->cell_type);
	if (index == -1)
		return ;
	if (ft_strchr(VERTICAL_DOOR_TYPES, g_texture_lookup[index].map_char))
		side = ray->vector.x;
	if (ft_strchr(HORIZONTAL_DOOR_TYPES, g_texture_lookup[index].map_char))
		side = -ray->vector.y;
	door_texture = dt->map.textures[ray->cell_type].texture;
	*texture = door_texture;
	if (side > 0)
		*tex_index = (texture->width * (tex_coor->y + (ray->percentage_of_image - ray->door->open_progress)));
	else
		*tex_index = (texture->width * (tex_coor->y + (1.0f - ray->percentage_of_image - ray->door->open_progress)));
}
int mark_all_cells_that_neighbour_doors(t_data *dt)
{
	t_door *door;
	int 	x;
	int		y;
	int	i;

	door = dt->doors;
	i = 0;
	while (i < dt->door_count)
	{
		x = door[i].cell_x;
		y = door[i].cell_y;
		if (x == 0 || y == 0 || x == (dt->map.map_size_cols - 1) || y == (dt->map.map_size_rows - 1))
		{
			i++;
			continue ;
		}
		if (door->orientation)
		{
			dt->map.map_data[y + 1][x].is_near_door = 1;
			dt->map.map_data[y - 1][x].is_near_door = 1;
			dt->map.map_data[y + 1][x].door = &door[i];
			dt->map.map_data[y - 1][x].door = &door[i];
		}
		else
		{
			dt->map.map_data[y][x + 1].is_near_door = 1;
			dt->map.map_data[y][x - 1].is_near_door = 1;
			dt->map.map_data[y][x + 1].door = &door[i];
			dt->map.map_data[y][x - 1].door = &door[i];
		}
		printf("Marked all neighbours of door with ID: %zu\n", door[i].id);
		i++;
	}
	return (EXIT_SUCCESS);
}
int	get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor)
{
	int			color;
	int			tex_index;
	t_texture	texture;
	t_door		*door;

	// default texture
	texture = dt->map.textures[ray->cell_type].texture;
	tex_coor->x = (texture.width * ray->percentage_of_image);
	tex_index = texture.width * tex_coor->y + tex_coor->x;
	
	if (ft_strchr(DOOR_TYPES, ray->hit_content))
		handle_door(&tex_index, ray, &texture, tex_coor, dt);

	if (ray->hit_cell->is_near_door && ray->hit_side == 'y')
	{
		texture = dt->map.textures[ray->door->texture_index].texture;
	}
	color = texture.texture_data[tex_index];
	return (color);
}
