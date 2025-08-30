/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sky_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:39:47 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_sky_image(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();

	printf(TXT_YELLOW ">>> LOADING SKY IMAGE\n" TXT_RESET);
	dt->sky_image = protected_malloc(sizeof(t_img), dt);
	dt->sky_image->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, SKY_TXT_PATHFILE, &w, &h);
	if (!dt->sky_image->mlx_img)
	{
		fprintf(stderr, "Failed to load sky texture\n");
		return (EXIT_FAILURE);
	}
	dt->sky_image->width = w;
	dt->sky_image->height = h;
	dt->sky_image->addr = mlx_get_data_addr(dt->sky_image->mlx_img,
			&dt->sky_image->bpp, &dt->sky_image->line_len,
			&dt->sky_image->endian);
	printf("Loaded sky texture: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	
	return (EXIT_SUCCESS);
}
