/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:26:04 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:26:06 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function name		ft_strmapi
//Prototype		char *ft_strmapi(char const *s, char (*f)(unsigned
//			int, char));
//Turn in files		-
//Parameters		s: The string on which to iterate.
//			f: The function to apply to each character.
//Return value		The string created from the successive applications
//			of ’f’.
//Returns			NULL if the allocation fails.
//External functs.	malloc
//Description		Applies the function f to each character of the
//			string s, passing its index as the first argument
//			and the character itself as the second. A new
//			string is created (using malloc(3)) to collect the
//r			results from the successive applications of f.

#include "libft.h"

//char	ft_modify(unsigned int i, char c)
//{
//	i = i;
//	if (c == 32)
//		return (c);
//	else
//		return (c + 4);
//}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

//#include <stdio.h>
//// Function to test ft_strmapi
//void test_ft_strmapi() {
//    const char *original = "abc";
//    char *result = ft_strmapi(original, ft_modify);

//    if (result) {
//        printf("Original: %s\n", original);
//        printf("Mapped: %s\n", result);
//        free(result);
//    } else {
//        printf("Memory allocation failed\n");
//    }
//}

//int main() {
//    test_ft_strmapi();
//    return (0);
//}