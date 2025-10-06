/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:34:29 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 15:33:22 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//memcpy - copy memory area

//#include <string.h>
//void *memcpy(void *dest, const void *src, size_t n);

//The memcpy() function copies n bytes from memory area src to 
// memory area dest.  The memory areas must not overlap.  
//Use memmove(3) if the memory areas do overlap.
//The memcpy() function returns a pointer to dest.

//if dest = src or n == 0, no job needs to be done
//if both are NULL (no memory assigned)

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	while (n--)
		ptr_dest[n] = ptr_src[n];
	return (dest);
}

//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	char src[11] = "teststring";
//	char dest[100];

//	printf("SRC: %s\n", src);
//	printf("DEST: %s\n", dest);
//	memcpy(dest, src, 4);
//	printf("SRC: %s\n", src);
//	printf("DEST: %s\n\n", dest);

//	char src2[] = "abc";
//	char dest2[100];

//	printf("SRC: %s\n", src2);
//	printf("DEST: %s\n", dest2);
//	ft_memcpy(dest2, src2, 4);
//	printf("SRC: %s\n", src2);
//	printf("DEST: %s\n", dest2);
//}