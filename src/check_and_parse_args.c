#include "cub3d.h"

void	check_and_parse_args(t_data *dt, int argc, char **argv)
{
	if (argc != 2)
	{
		error_msg("Try again! Format ./cub3D <name_file>.cub\n", 1);
		exit(1);
	}
	init_dt(dt);
	if (check_and_parse_map_file(dt, argv[1]))
	{
		free_dt(dt);
		exit(1);
	}
}