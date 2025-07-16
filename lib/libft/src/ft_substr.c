/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:26:18 by dmlasko           #+#    #+#             */
/*   Updated: 2025/07/14 14:38:16 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s:  The string from which to create the substring.
// start:  The start index of the substring in the string ’s’.
// len:  The maximum length of the substring.
/* Description
 Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.*/

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (start + len > strlen)
		len = strlen - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

//// cc ft_substr.c ft_strlen.c ft_strdup.c && ./a.out
//#include <stdio.h>
//int	main(void)
//{
//	char str[] = "tripouille";
//	char *result;
//	result =  ft_substr(str, 0, 42000);
//	printf("%s\n", result);
//	free(result);
//}
