/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:39:14 by dmlasko           #+#    #+#             */
/*   Updated: 2025/07/01 22:59:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function name		ft_itoa
//Prototype		char *ft_itoa(int n);
//Turn in files		-
//Parameters		n: the integer to convert.
//Return value		The string representing the integer.
//			NULL if the allocation fails.
//External functs.	malloc
//Description		Allocates (with malloc(3)) and returns a string
//			representing the integer received as an argument.
//			Negative numbers must be handled.

#include "libft.h"

// str to int
int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_negative;
	int		str_len;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	else
		n = -n;
	str_len = ft_int_len(n) + is_negative;
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	while (str_len > 0)
	{
		str[str_len - 1] = '0' - n % 10;
		n = n / 10;
		str_len--;
	}
	if (is_negative)
		str[str_len] = '-';
	return ((char *)str);
}

//#include <stdio.h>
//int	main(void)
//{
//	int n = -10;
//	//printf("%d\n", ft_int_len(n));
//	printf("%s\n", ft_itoa(n));
//}
