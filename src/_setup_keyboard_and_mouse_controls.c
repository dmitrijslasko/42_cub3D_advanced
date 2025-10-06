#include "cub3d.h"

int	setup_keyboard_and_mouse_controls(t_data *dt)
{
	printf("Setting keyboard and mouse hooks...\n");
	setup_keyboard_hooks(dt);
	if (ENABLE_MOUSE)
		setup_mouse_hooks(dt);
	return (EXIT_SUCCESS);
}