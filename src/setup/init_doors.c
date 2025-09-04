/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:43 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/18 16:03:34 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_a_door(t_data *dt, t_map *map, t_door **door_ptr, \
						int curr_row, int curr_col)
{
	t_door	*door;
	char 	door_type;

	door_type =  get_cell_type_by_coordinates(map, curr_row, curr_col);

	door = *door_ptr;

	door->id = door - dt->doors;
	door->side_texture_index = get_lookup_table_index_cell_type_by_map_char(door_type) + 1;
	door->cell_x = curr_col;
	door->cell_y = curr_row;
	door->pos_x = DEF_DOOR_OFFSET_X;
	door->pos_y = DEF_DOOR_OFFSET_Y;
	door->is_opening = 0;
	door->open_progress = 0.0f;
	if (ft_strchr(VERTICAL_DOOR_TYPES, map->map_data[curr_row][curr_col].cell_char))
		door->orientation = 1;
	else
		door->orientation = 0;
	door->speed = DEF_DOOR_SPEED;
	door->state = 0;
	printf("Door [%2zu] at X Y (%3d, %3d) added. Orientation: %d\n",
		door->id, curr_col, curr_row, door->orientation);
	printf("Door side texture for door [%2zu] added: %d\n-------------\n",
		door->id, door->side_texture_index);
	(*door_ptr)++;
}

void	init_doors(t_data *dt, t_level *level, t_map *map)
{
	t_door	*door_ptr;
	int		curr_row;
	int		curr_col;
	char	door_type;
	size_t	door_count;

	print_separator_default();
	printf(TXT_YELLOW ">>> INITIALISING DOORS\n" TXT_RESET);
	printf("Level: #%d\n", level->id);

	door_count = count_elements_in_the_map(map, DOOR_TYPES);
	level->door_count = door_count;
	printf("Doors elements found: %zu\n", door_count);

	level->doors = protected_malloc(sizeof(t_door) * door_count, dt);
	
	door_ptr = level->doors;

	curr_row = 0;
	while (curr_row < map->map_size_rows)
	{
		curr_col = 0;
		while (curr_col < map->map_size_cols)
		{
			door_type =  get_cell_type_by_coordinates(map, curr_row, curr_col);
			if (ft_strchr(DOOR_TYPES, door_type))
				init_a_door(dt, map, &door_ptr, curr_row, curr_col);
			curr_col++;
		}
		curr_row++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
}
