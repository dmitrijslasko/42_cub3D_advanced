#include "cub3d.h"

void	check_and_parse_map(t_data *dt, int argc, char *mapfile)
{	
	// free_dt(dt);
	if (check_and_parse_mapfile(dt, mapfile))
	{
		error_msg("Error parsing the provided map...\n", 1);
		free_dt(dt);
	}
}

void	check_and_parse_args(t_data *dt, int argc, char **argv)
{
	// check argument count
	if (argc != 2)
	{
		error_msg("Try again! Format ./cub3D <name_file>.cub\n", 1);
		exit(1);
	}
	
	if (check_and_parse_mapfile(dt, argv[1]))
	{
		error_msg("Error parsing the provided map...\n", 1);
		free_dt(dt);
	}
}
