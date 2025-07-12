/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:34 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:35 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_view(t_data *dt)
{
	dt->view->screen_center_y = WINDOW_H / 2;
	dt->view->z_plane_height = 0.5f;
	dt->view->show_minimap = MINIMAP_ENABLE_ON_START;
	dt->view->show_debug_info = 0;
	dt->view->show_door_open_message = 0;
}
