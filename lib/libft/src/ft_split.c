/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:21:58 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:40:17 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function name		ft_split
//Prototype		char **ft_split(char const *s, char c);
//Turn in files		-
//Parameters s:		The string to be split.
//			c: The delimiter character.
//Return value		The array of new strings resulting from the split.
//			NULL if the allocation fails.
//External functs. 	malloc, free
//Description 		Allocates (with malloc(3)) and returns an array
//			of strings obtained by splitting ’s’ using the
//			character ’c’ as a delimiter. The array must end
//			with a NULL pointer.

#include "libft.h"

int	ft_count_strings(char const *s, char const c)
{
	int	string_count;

	string_count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			string_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (string_count);
}

char	*ft_malloc_str(char const *s, char sep)
{
	int		i;
	char	*str;
	char	*ptr_str;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ptr_str = str;
	while (i--)
		*ptr_str++ = *s++;
	*ptr_str = '\0';
	return (str);
}

void	ft_free_split(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[i] = ft_malloc_str(s, c);
			if (array[i++] == NULL)
			{
				ft_free_split(array, i);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
		}
	}
	array[i] = NULL;
	return (array);
}

//#include <stdio.h>
// int	main (int argc, char *argv[])
// {
// 	if (argc > 0)
//	{
//		//printf("%s\t\tWORD COUNT: %d\n", "abc,", ft_count_strings("abc,", ','));
//		//printf("%s\t\tWORD COUNT: %d\n", ",abc", ft_count_strings(",abc", ','));
//		//printf("%s\t\tWORD COUNT: %d\n", ",,,", ft_count_strings(",,,", ','));
//		//printf("%s\t\tWORD COUNT: %d\n", ",", ft_count_strings(",", ','));
//		//printf("%s\t\tWORD COUNT: %d\n", "", ft_count_strings("", ','));
//	}
//	char *s = "^^^1^^2a,^^^^3^^^^--h^^^^";
//	char c = '3';
//	char **array = ft_split(s, c);
//	//printf("%s\t\tWORD COUNT: %d\n", s, ft_count_strings(s, c));
//	while (*array)
//	{
//		printf("%s\n", *array);
//		array++;
//	}
//	//ft_free_split(array, ft_strlen(s));
//	//free(array);
// 	return (0);
// }