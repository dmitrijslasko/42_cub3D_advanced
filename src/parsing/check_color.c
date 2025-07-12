/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:08 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_color(char *one_color)
{
	long	r;

	if (!check_only_number(one_color))
		return (error_msg("Color indefined", 0));
	r = ft_atoi(one_color);
	if (r > 255)
		return (error_msg("Color indefined", 0));
	return (1);
}
