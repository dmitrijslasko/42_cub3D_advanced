/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:35:36 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:35:05 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

//#include <string.h>
//#include <assert.h>
//#include <stdio.h>
//int	main(void)
//{
//	char str[] = "teste";
//	int c = 1024;
//	//printf("%p\n", str);
	//ft_strchr(str, '\0');
//	printf("%p\n", ft_strchr(str, c));
//	//printf("%d\n", ft_strchr(str,c)==strchr(str,c));
//	//assert(ft_strchr(str,c)==strchr(str,c));
//}