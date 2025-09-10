/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ui_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:11 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_ui_messages(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING UI MESSAGES\n" TXT_RESET);
	dt->message_img = protected_malloc(sizeof(t_img), dt);
	dt->message_img->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr,
			"./ui/open-close-door.xpm", &w, &h);
	if (!dt->message_img->mlx_img)
	{
		fprintf(stderr, "Failed to load message_img\n");
		return (EXIT_FAILURE);
	}
	dt->message_img->width = w;
	dt->message_img->height = h;
	dt->message_img->addr = mlx_get_data_addr(dt->message_img->mlx_img,
			&dt->message_img->bpp, &dt->message_img->line_len,
			&dt->message_img->endian);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
