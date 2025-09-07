/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:46 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 16:51:17 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mouse(t_mouse *mouse)
{
	mouse->suppress_mouse_frames = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	mouse->lmb_press_count = 0;
}

void	init_texture(t_texture *texture)
{
	if (!texture)
		return ;
	texture->texture_img = NULL;
	texture->texture_data = NULL;
	texture->xpm_file_pathfile = NULL;
}

void	init_map(t_map	*map)
{
	size_t	i;

	printf("Initialising map...\n");
	map->map_data = NULL;
	i = 0;
	
	while (i < NUMBER_TEXTURES)
	{
		init_texture(&map->textures[i].texture);
		map->textures[i++].is_color = 0;
	}
}

void	init_img(t_img *img)
{
	if (!img)
		return ;
	img->addr = NULL;
	img->mlx_img = NULL;
}

void	init_dt(t_data *dt)
{
	printf("Initializing data struct...\n");
	
	dt->map = NULL;
	dt->rays = NULL;
	dt->doors = NULL;
	dt->view = NULL;
	init_mouse(&dt->mouse);
	init_graphic(dt);
	dt->frames_drawn_count = 0;
	dt->background_music = NULL;
	dt->sprite_pulse_coef = 0;
	dt->sprite_pulse_step = 1;
}
