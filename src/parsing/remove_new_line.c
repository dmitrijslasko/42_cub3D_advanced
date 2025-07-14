/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 17:19:04 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_new_line(char *str)
{
	size_t	last_pos;

	if (!str)
		return ;
	last_pos = ft_strlen(str);
	if (last_pos != 0 && str[last_pos - 1] == '\n')
		str[last_pos - 1] = '\0';
}
