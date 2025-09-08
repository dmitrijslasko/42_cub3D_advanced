/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:34 by fvargas           #+#    #+#             */
/*   Updated: 2025/09/08 16:42:06 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_view(t_data *dt)
{
	dt->view->screen_center_y = WINDOW_H / 2;

	dt->view->z_plane_height = 0.2f;

	dt->view->show_minimap = MINIMAP_ENABLE_ON_START;

	dt->view->show_door_open_message = 0;
	dt->view->active_prompt_message = NO_MESSAGE;

	dt->view->show_debug_info = SHOW_DEBUG_INFO;
	dt->view->show_targeted_sprite = SHOW_DEBUG_INFO;
}
