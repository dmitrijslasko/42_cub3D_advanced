#include "cub3d.h"

int	update_prompt_message(t_data *dt)
{
	t_coor	cell_ahead;

	debug_print("Updating prompt messages!\n");
	cell_ahead = get_cell_ahead(dt);
	dt->player.cell_type_ahead = get_cell_type(dt->map, &cell_ahead);
	
	dt->view->show_door_open_message = ft_strchr(DOOR_TYPES, dt->player.cell_type_ahead);
	return (EXIT_SUCCESS);
}