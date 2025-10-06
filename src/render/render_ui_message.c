/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:23 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:34:16 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_ui_message(t_data *dt)
{
	char			*src_pixel;
	unsigned int	color;
	t_coor			draw;
	int				row;
	int				col;

	row = 0;
	while (row < dt->message_img[0].height)
	{
		col = 0;
		while (col < dt->message_img[0].width)
		{
			src_pixel = dt->message_img[0].addr + row * \
				dt->message_img[0].line_len + col * dt->message_img->bpp / 8;
			color = *(unsigned int *)src_pixel;
			draw.x = ((WINDOW_W - dt->message_img[0].width) / 2) + col;
			draw.y = UI_MESSAGE_OFFSET_Y + row;
			if (color != BLACK)
				img_pix_put(dt->final_frame_img, draw.x, draw.y, color);
			col++;
		}
		row++;
	}
	return (EXIT_SUCCESS);
}
