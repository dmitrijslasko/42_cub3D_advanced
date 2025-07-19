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

int is_in_list(char *str, char *list)
{
    for (int i = 0; i < ft_strlen(list); i++)
        if (ft_strchr(str, list[i]))
            return 1;
    return 0;
}

t_texture *handle_door(int *tex_index, t_ray *ray, t_coor *tex_coor, t_data *dt)
{
    float side;
    int index = get_lookup_table_index_cell_type(ray->cell_type);

    if (index == -1)
        return NULL;

    if (ft_strchr(VERTICAL_DOOR_TYPES, g_texture_lookup[index].map_char))
        side = ray->vector.x;
    else if (ft_strchr(HORIZONTAL_DOOR_TYPES, g_texture_lookup[index].map_char))
        side = -ray->vector.y;
    else
        return NULL;

    t_texture *texture = &dt->map.textures[ray->cell_type].texture;

    if (side > 0)
        *tex_index = texture->width * (tex_coor->y + (ray->percentage_of_image - ray->door->open_progress));
    else
        *tex_index = texture->width * (tex_coor->y + (1.0f - ray->percentage_of_image - ray->door->open_progress));
	*tex_index = 1;

    return texture;
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
		if (door[i].orientation == 1)
		{
			dt->map.map_data[y - 1][x].is_near_door = 1;
			dt->map.map_data[y + 1][x].is_near_door = 1;
			printf("Marked cell: %d %d\n", x, y - 1);
			printf("Marked cell: %d %d\n", x, y + 1);
			dt->map.map_data[y - 1][x].door = &door[i];
			dt->map.map_data[y + 1][x].door = &door[i];
		}
		else if (door[i].orientation == 0)
		{
			dt->map.map_data[y][x - 1].is_near_door = 1;
			dt->map.map_data[y][x + 1].is_near_door = 1;
			printf("Marked cell: %d %d\n", x - 1, y);
			printf("Marked cell: %d %d\n", x + 1, y);
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
	int			side_texture_index;
	t_texture *texture = NULL;

	if (ft_strchr(DOOR_TYPES, ray->hit_content))
	{
		texture = handle_door(&tex_index, ray, tex_coor, dt);
		if (!texture) // fallback in case handle_door fails
			texture = &dt->map.textures[ray->cell_type].texture;
	}
	else if (ray->hit_cell->is_near_door && ray->hit_side == 'y' && ray->door && ray->door->orientation == 1)
	{
		int side_texture_index = ray->door->side_texture_index;
		texture = &dt->map.textures[side_texture_index].texture;
		tex_coor->x = texture->width * ray->percentage_of_image;
		tex_index = texture->width * tex_coor->y + tex_coor->x;
	}
	else if (ray->hit_cell->is_near_door && ray->hit_side == 'x' && ray->door && ray->door->orientation == 0)
	{
		int side_texture_index = ray->door->side_texture_index;
		texture = &dt->map.textures[side_texture_index].texture;
		tex_coor->x = texture->width * ray->percentage_of_image;
		tex_index = texture->width * tex_coor->y + tex_coor->x;
	}
	else
	{
		texture = &dt->map.textures[ray->cell_type].texture;
		tex_coor->x = texture->width * ray->percentage_of_image;
		tex_index = texture->width * tex_coor->y + tex_coor->x;
	}

	color = texture->texture_data[tex_index];

	return (color);
}
