/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:46 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:09:47 by fvargas          ###   ########.fr       */
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
	texture->file = NULL;
}

void	init_map(t_map	*map)
{
	size_t	i;

	map->map_data = NULL;
	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		init_texture(&map->wall_tile[i].texture);
		map->wall_tile[i++].is_color = 0;
	}
	init_texture(&map->door.texture);
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
	dt->doors = NULL;
	dt->rays = NULL;
	dt->sprites = NULL;
	dt->sprite_textures = NULL;
	dt->sprite_count = 0;
	dt->sprite_texture_count = 0;
	dt->view = NULL;
	dt->welcome_img = NULL;
	dt->background_music = NULL;
	dt->frames_drawn_count = 0;
	dt->has_changed = 1;
	init_mouse(&dt->mouse);
	init_map(&dt->map);
	init_graphic(dt);
}
