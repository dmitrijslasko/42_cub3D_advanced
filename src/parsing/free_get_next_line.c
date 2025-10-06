/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:41 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 14:41:35 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*free_line_get_next(char *line, int fd)
{
	char	*new_line;

	if (line)
		free(line);
	line = NULL;
	new_line = get_next_line(fd);
	remove_new_line(new_line);
	line = new_line;
	return (new_line);
}
