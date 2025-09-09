#include "cub3d.h"

int trigger_all_enemies(t_data *dt, int new_state)
{
	// puts("triggering all enemies!");
	for (size_t i = 0; i < dt->levels[dt->active_level].sprite_count; i++)
	{
		if (dt->sprites[i].type == ENEMY)
			dt->levels[dt->active_level].sprites[i].state = new_state;
	}
	return (EXIT_SUCCESS);
}