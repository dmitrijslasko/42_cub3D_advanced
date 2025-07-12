/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:10:59 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:35:30 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name	ft_strjoin
// Prototype		char *ft_strjoin(char const *s1, char const *s2);
// Turn in files 	-
// Parameters 		s1: The prefix string.
// 			s2: The suffix string.
// Return value 	The new string.
// 			NULL if the allocation fails.
//External functs. 	malloc
//Description		Allocates (with malloc(3)) and returns a new
// 			string, which is the result of the concatenation
// 			of ’s1’ and ’s2’.

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	char	*ptr;

	concat_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concat_str == NULL)
		return (NULL);
	ptr = concat_str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (concat_str);
}

//// cc ft_strjoin.c ft_strlen.c && ./a.out
//#include <stdio.h>
//int	main(void)
//{
//	char s1[] = "I will ";
//	char s2[] = "concatenate this";
//	printf("%s\n", ft_strjoin(s1, s2));
//}