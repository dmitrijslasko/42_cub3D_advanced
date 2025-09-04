#include "cub3d.h"

t_level *get_curr_level(t_data *dt)
{
	return (&dt->levels[dt->active_level]);
}