/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:11:21 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:11:22 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_separator_default(void)
{
	int		i;
	size_t	j;

	j = 0;
	while (j < DEF_SEPARATOR_COUNT)
	{
		i = 0;
		while (i++ < DEF_SEPARATOR_WIDTH)
			ft_putstr_fd(DEF_SEPARATOR_CHAR, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		j++;
	}
}

void	print_separator(size_t count, char *c)
{
	int		i;
	size_t	j;

	j = 0;
	while (j < count)
	{
		i = 0;
		while (i++ < DEF_SEPARATOR_WIDTH)
			ft_putstr_fd(c, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		j++;
	}
}
