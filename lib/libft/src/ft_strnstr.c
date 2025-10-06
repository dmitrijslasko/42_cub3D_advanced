/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:38:17 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:38:31 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If little is an empty string, big is returned; 
// if little occurs nowhere in big, NULL is returned; 
// otherwise a pointer to the first character of the 
// first occurrence of little is returned.

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big != '\0' && len > 0 && len >= little_len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// int	main(int argc, char *argv[])
// {
// 	if (argc > 0)
// 	{
// 		// assert(ft_strncmp(argv[1], "test", 6) == 0);
// 		printf("%s\n", ft_strnstr("aaabcabcd", "abcd", 9));
// 		// printf("%s", argv[1]);
// 	}
// }