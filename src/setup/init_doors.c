/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:43 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:17:18 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_a_door(t_data *dt, t_door **door_ptr, \
						int curr_row, int curr_col)
{
	t_door	*door_ptr_ref;
	char 	door_type;
				
	door_type =  get_cell_type_by_coordinates(&dt->map,
						curr_row, curr_col);

	door_ptr_ref = *door_ptr;
	door_ptr_ref->id = door_ptr_ref - dt->doors;
	door_ptr_ref->texture_index = get_lookup_table_index_cell_type_by_map_char(door_type) + 5;
	door_ptr_ref->cell_x = curr_col;
	door_ptr_ref->cell_y = curr_row;
	door_ptr_ref->pos_x = DEF_DOOR_OFFSET_X;
	door_ptr_ref->pos_y = DEF_DOOR_OFFSET_Y;
	door_ptr_ref->open_progress = 0.0f;
	if (ft_strchr(VERTICAL_DOOR_TYPES, dt->map.map_data[curr_row][curr_col].cell_char))
		door_ptr_ref->orientation = 1;
	else
		door_ptr_ref->orientation = 0;
	door_ptr_ref->speed = DEF_DOOR_SPEED;
	door_ptr_ref->state = 0;
	printf("Door [%2zu] at X Y (%3d, %3d) added. Orientation: %d\n",
		door_ptr_ref->id, curr_col, curr_row, door_ptr_ref->orientation);
	(*door_ptr)++;
}

void	init_doors(t_data *dt)
{
	t_door	*door_ptr;
	int		curr_row;
	int		curr_col;
	char	door_type;

	print_separator_default();
	printf(TXT_YELLOW ">>> INITIALISING DOORS\n" TXT_RESET);
	dt->door_count = count_elements_in_the_map(&dt->map, DOOR_TYPES);
	printf("Doors found: %zu\n", dt->door_count);
	dt->doors = protected_malloc(sizeof(t_door) * dt->door_count, dt);
	door_ptr = dt->doors;
	curr_row = 0;
	while (curr_row < dt->map.map_size_rows)
	{
		curr_col = 0;
		while (curr_col < dt->map.map_size_cols)
		{
			door_type =  get_cell_type_by_coordinates(&dt->map,
						curr_row, curr_col);
			if (ft_strchr(DOOR_TYPES, door_type))
				init_a_door(dt, &door_ptr, curr_row, curr_col);
			curr_col++;
		}
		curr_row++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
}
