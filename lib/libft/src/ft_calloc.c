/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:24:02 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:35:20 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocates memory of (count * size) bytes; 
//essentially same stuff as malloc (size)
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	if (memory == NULL)
	{
		free(memory);
		return (NULL);
	}
	return (memory);
}

// #include <stdio.h>
// int	main(void)
// {
// 	void *memory;
// 	memory = ft_calloc(10, 8);
//	ft_memset(memory, 97, 80);
// 	printf("%s", (char *)memory);
// }