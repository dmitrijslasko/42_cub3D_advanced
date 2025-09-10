#include "cub3d.h"

void	check_and_parse_all_maps(t_data *dt, int argc, char *mapfiles[])
{	
	size_t	i;

	i = 0;
	while (mapfiles[i])
	{
		print_separator_default();
		printf("Parsing map #%d\n", i + 1);
		if (check_and_parse_mapfile(dt, mapfiles[i], i))
		{
			error_msg("Error parsing the provided map...\n", 1);
			free_dt(dt);
		}
		printf(">>>>>>> MAP %d PARSED!\n", i);
		print_separator(3, "*");
		i++;
	}
}

// void	check_and_parse_map(t_data *dt, int argc, char *mapfile)
// {	
// 	if (check_and_parse_mapfile(dt, mapfile, 0))
// 	{
// 		error_msg("Error parsing the provided map...\n", 1);
// 		free_dt(dt);
// 	}
// }

// void	check_and_parse_args(t_data *dt, int argc, char **argv)
// {
// 	printf("Checking and parsing arguments...\n");
// 	// check argument count
// 	if (argc != 2)
// 	{
// 		error_msg("Try again! Format ./cub3D <name_file>.cub\n", 1);
// 		exit(1);
// 	}
// 	printf("Checking and parsing mapfile...\n");
// 	if (check_and_parse_mapfile(dt, argv[1], 0))
// 	{
// 		error_msg("Error parsing the provided map...\n", 1);
// 		free_dt(dt);
// 	}
// }
