/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:41 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 17:42:47 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*free_line_get_next(char *line, int fd)
{
	char	*str_new;

	//if (line)
	//	free(line);
	line = NULL;

	str_new = get_next_line(fd);
	remove_new_line(str_new);
	line = str_new;
	return (str_new);
}
