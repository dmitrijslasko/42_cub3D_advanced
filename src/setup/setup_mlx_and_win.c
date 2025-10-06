/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_and_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:31 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:32 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup_mlx_and_win(t_data *dt)
{
	printf("Creating MLX pointer...");
	dt->mlx_ptr = mlx_init();
	if (dt->mlx_ptr == NULL)
		return (MLX_ERROR);
	printf(" Done!\n");
	printf("Creating a new MLX window...");
	dt->win_ptr = mlx_new_window(dt->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (dt->win_ptr == NULL)
		return (MLX_ERROR);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
