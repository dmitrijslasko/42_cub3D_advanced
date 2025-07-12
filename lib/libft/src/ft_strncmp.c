/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:36:18 by dmlasko           #+#    #+#             */
/*   Updated: 2025/03/10 17:48:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strcmp, strncmp - compare two strings
#include <stddef.h>
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

//int	ft_strncmp(const char *s1, const char *s2, size_t n)
//{
//	size_t i;

//	i = 0;
//	if (n == 0)
//		return (0);
//	while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i])
//		i++;
//	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
//}

// #include <string.h>
// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	if (argc > 1)
// 		printf("%d\n", ft_strncmp(argv[1], "test", 4));
// 	else
// 	{
// 		char	s1[] = "test\200";
// 		char	s2[] = "te";
// 		printf("%d\n", ft_strncmp(s1, s2, 5));
// 	}
// }
