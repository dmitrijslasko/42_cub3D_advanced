/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grafic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:48 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:09:49 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_graphic(t_data *dt)
{
	dt->mlx_ptr = NULL;
	dt->win_ptr = NULL;
	
	dt->final_frame_img = NULL;
	dt->raycasting_scene_img = NULL;
	dt->minimap_base_img = NULL;
	dt->minimap_img = NULL;
	dt->message_img = NULL;
}
