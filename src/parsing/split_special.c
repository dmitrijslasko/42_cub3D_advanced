/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:24 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 13:54:19 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_words(char const *s, char *delimiters)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(delimiters, s[i]))
			i++;
		if (s[i] && !ft_strchr(delimiters, s[i]))
			count++;
		while (s[i] && !ft_strchr(delimiters, s[i]))
			i++;
		if (s[i])
			i++;
	}
	return (count);
}

static void	get_word(char const *s, char *delimiters, char **a_word, size_t *j)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && !ft_strchr(delimiters, s[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
	{
		free_array(a_word);
		return ;
	}
	word[i] = '\0';
	while (--i >= 0)
		word[i] = s[i];
	*a_word = word;
	(*j) += ft_strlen(word);
}

static char	**split(char const *s, char *delimiters, char **a, size_t n)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (s[j] && ft_strchr(delimiters, s[j]))
			j++;
		get_word(&s[j], delimiters, &a[i], &j);
		if (!a[i++])
		{
			free_array(a);
			return (NULL);
		}
	}
	a[i] = NULL;
	return (a);
}

char	**ft_split_by_multiple_delimiters(const char *s, char *c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (0);
	size = count_words(s, c);
	array = (char **)malloc((size + 1) * sizeof(char *));
	if (!array)
		return (0);
	array = split(s, c, array, size);
	return (array);
}
