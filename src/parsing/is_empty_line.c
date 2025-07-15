/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:58 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 14:18:36 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
