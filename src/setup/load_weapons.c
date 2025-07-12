/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/10 20:11:19 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_weapon_frame(t_data *dt, int i, const char* filename)
{
	int	w;
	int	h;

	dt->weapon_img[i].mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr,
			filename, &w, &h);
	if (!dt->weapon_img[i].mlx_img)
	{
		fprintf(stderr, "Failed to load weapon_img\n");
		return (EXIT_FAILURE);
	}
	dt->weapon_img[i].width = w;
	dt->weapon_img[i].height = h;
	dt->weapon_img[i].addr = mlx_get_data_addr(dt->weapon_img[i].mlx_img,
			&dt->weapon_img[i].bpp, &dt->weapon_img[i].line_len,
			&dt->weapon_img[i].endian);
	printf(TXT_GREEN "Loaded frame: %s\n" TXT_RESET, filename);
}

int	load_weapons(t_data *dt)
{

	size_t	i;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING WEAPONS\n" TXT_RESET);
	dt->weapon_img = protected_malloc(sizeof(t_img) * 5, dt);
	i = 0;
	while (i < 5)
	{
		char path[64];
		snprintf(path, sizeof(path), "./ui/pistol/frame%d.xpm", i);
		load_weapon_frame(dt, i, path);
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
