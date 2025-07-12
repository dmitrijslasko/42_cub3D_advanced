/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:38:34 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/01 16:38:37 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// toupper - convert char to lowercase
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

//#include <stdio.h>
//int	main(void)
//{
//	printf("%c", ft_tolower('A'));
//}