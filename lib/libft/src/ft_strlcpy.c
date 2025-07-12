/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:18 by dmlasko           #+#    #+#             */
/*   Updated: 2025/03/10 16:42:15 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size != 0 && dest)
	{
		i = 0;
		while (i < (size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

//#include <assert.h>
//#include <bsd/string.h>
//int	main(void)
//{
//	//assert(ft_strlcpy(NULL, "test", 4) == strlcpy(NULL, "test", 4));
//	ft_strlcpy("test", NULL, 4);
//	//strlcpy("test", NULL, 4);
//}
