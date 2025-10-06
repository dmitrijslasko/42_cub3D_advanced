/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:35:31 by dmlasko           #+#    #+#             */
/*   Updated: 2025/05/06 16:41:49 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset - fill memory with a constant byte

// #include <string.h>
// void *memset(void *s, int c, size_t n);

// The memset() function fills the first n bytes of the memory area
// pointed to by s with the constant byte c.
// The memset() function returns a pointer to the memory area s.
// create a pointer, cast the original void pointer to the
// created pointer, write

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = c;
	return (b);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	// stdlib.h
// 	void *memory = malloc(10);
// 	printf("%zu\n", sizeof(memory));
// 	memset(memory, 'c', 4);
// 	printf("%s\n", (char *)memory);

// 	// ft
// 	void *ft_memory = malloc(10);
// 	printf("%zu\n", strlen(ft_memory));
// 	ft_memset(ft_memory, 'c', 20);
// 	printf("%zu\n", strlen(ft_memory));
// 	printf("%s\n", (char *)ft_memory);
// }
