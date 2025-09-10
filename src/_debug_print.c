#include "cub3d.h"

int	debug_print(char *str)
{
	if (!DEBUG_PRINT)
		return (0);
	return (printf(str));
}