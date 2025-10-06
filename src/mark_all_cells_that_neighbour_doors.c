#include "cub3d.h"

int mark_all_cells_that_neighbour_doors(t_data *dt, t_level *level, t_map *map)
{
	t_door *door;
	int 	x;
	int		y;
	int	i;

	door = level->doors;
	i = 0;
	while (i < level->door_count)
	{
		x = door[i].cell_x;
		y = door[i].cell_y;
		if (x == 0 || y == 0 || x == (map->map_size_cols - 1) || y == (map->map_size_rows - 1))
		{
			i++;
			continue ;
		}
		if (door[i].orientation == 1)
		{
			map->map_data[y - 1][x].is_near_door = 1;
			map->map_data[y + 1][x].is_near_door = 1;
			printf("Marked cell: %d %d\n", x, y - 1);
			printf("Marked cell: %d %d\n", x, y + 1);
			map->map_data[y - 1][x].door = &door[i];
			map->map_data[y + 1][x].door = &door[i];
		}
		else if (door[i].orientation == 0)
		{
			map->map_data[y][x - 1].is_near_door = 1;
			map->map_data[y][x + 1].is_near_door = 1;
			printf("Marked cell: %d %d\n", x - 1, y);
			printf("Marked cell: %d %d\n", x + 1, y);
			map->map_data[y][x + 1].door = &door[i];
			map->map_data[y][x - 1].door = &door[i];
		}
		printf("Marked all neighbours of door with ID: %zu\n", door[i].id);
		i++;
	}
	puts("Done!");
	return (EXIT_SUCCESS);
}