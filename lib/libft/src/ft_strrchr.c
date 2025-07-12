/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:38:24 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:39:01 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

//char	*ft_strrchr(const char *s, int c)
//{
//	int		i;
//	char	*ptr;

//	i = 0;
//	ptr = 0;
//	while (s[i])
//	{
//		if (s[i] == c)
//			ptr = (char *)(s + i);
//		i++;
//	}
//	if (s[i] == c)
//		ptr = (char *)(s + i);
//	return (ptr);
//}
