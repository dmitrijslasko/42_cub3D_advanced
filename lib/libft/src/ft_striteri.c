/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:25:47 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:25:49 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_striteri works the same way as ft_strmapi does.
// The difference between ft_striteri and ft_strmapi is that ft_striteri 
// doesn't return anything and works directly on the original string.

//void	ft_modify(unsigned int i, char *c)
//{
//	*c[i] += 2;
//}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

//#include <stdio.h>
//// Function to test ft_strmapi
//void test_ft_strteri() {
//    char original = "abc";
//    printf("BEFORE: %s\n", original);
//    ft_striteri(original, ft_modify);
//    printf("AFTER: %s\n", original);
//}

//int main() {
//    test_ft_strteri();
//    return (0);
//}