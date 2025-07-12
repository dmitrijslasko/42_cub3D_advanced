/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:38:41 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:26:47 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// toupper - convert char to uppercase
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

//#include <stdio.h>
//int	main(void)
//{
//	printf("%c", ft_toupper('3'));
//}