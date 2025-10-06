/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:40 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:41 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*protected_malloc(size_t size, t_data *dt)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		perror("Failed to allocate memory.");
		if (dt)
			free_dt(dt);
		exit (1);
	}
	ft_memset(ptr, '\0', size);
	return (ptr);
}
