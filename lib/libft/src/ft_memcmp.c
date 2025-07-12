/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:33:42 by dmlasko           #+#    #+#             */
/*   Updated: 2025/03/30 16:55:29 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compares two memory areas' to see if they have the same content
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}

//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>

//int	main(void)
//{
//	void	*str1;
//	void	*str2;

//	str1 = malloc(6);
//	str2 = malloc(6);

//	strcpy(str1, "t\200");
//	strcpy(str2, "t\0");
//	printf("%d\n", ft_memcmp(str1, str2, 2));
//}
