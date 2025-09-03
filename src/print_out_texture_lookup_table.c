#include "cub3d.h"

int print_out_texture_lookup_table(t_data *dt)
{
	int	i;

	i = 0;
	printf(TXT_CYAN">>> Printing out the texture lookup table!\n"TXT_RESET);
	while (g_texture_lookup[i].mapfile_key)
	{
		printf("%25s [%4s, %2d] : %s\n",
			g_texture_lookup[i].description,
			g_texture_lookup[i].mapfile_key,
			g_texture_lookup[i].texture_type,
			dt->map->textures[i].texture.xpm_file
			);
		i++;
	}
	print_separator_default();
	return (EXIT_SUCCESS);
}