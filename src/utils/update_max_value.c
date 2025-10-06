/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_max_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:11:35 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:11:36 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_value_max(int *count, char *line)
{
	if (*count < (int) ft_strlen(line))
		*count = (int) ft_strlen(line);
}
