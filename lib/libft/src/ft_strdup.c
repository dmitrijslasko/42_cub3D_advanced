/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:25:39 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:39:26 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strdup() function allocates sufficient memory 
// for a copy of the string s1, does the copy, 
// and returns a pointer to it.  The pointer may 
// subsequently be used as an argument to
// the function free(3).

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*ptr;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) +1));
	if (!s2)
		return (NULL);
	ptr = s2;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (s2);
}

//#include <stdio.h>
// int	main(void)
// {
//	char str[] = "Test_string";
//	printf("%s\n", str);
//	char *str2 = ft_strdup(str);
//	printf("%s\n", str2);
// }