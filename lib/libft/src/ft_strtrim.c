/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:29:57 by dmlasko           #+#    #+#             */
/*   Updated: 2025/05/04 13:14:28 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function name		ft_strtrim
//Prototype		char *ft_strtrim(char const *s1, char const *set);
//Turn in files		-
//Parameters		s1: The string to be trimmed.
//			set: The reference set of characters to trim.
//Return value		The trimmed string.
//			NULL if the allocation fails.
//External functs.	malloc
//Description		Allocates (with malloc(3)) and returns a copy of
//			’s1’ with the characters specified in ’set’ removed
//			from the beginning and the end of the string.

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

// #include <stdio.h>
// // cc ft_strtrim.c ft_strlen.c && ./a.out
// int	main(void)
// {
// 	char s1[] = "   lorem \n ipsum \t dolor \n sit \t amet   ";
// 	char trimmed_str[] = " ";
// 	printf("%s\n", ft_strtrim(s1, trimmed_str));
// }
