/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:11 by fvargas          ###   ########.fr       */
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
