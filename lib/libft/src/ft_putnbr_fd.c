/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:25:24 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:33:00 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[10];
	int		i;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	else
		n = -n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		i = 0;
		while (n)
		{
			buffer[i++] = '0' - n % 10;
			n /= 10;
		}
		if (is_negative)
			ft_putchar_fd('-', fd);
		while (i--)
			ft_putchar_fd(buffer[i], fd);
	}
}

//int	main(void)
//{
//	int n = 0;
//	ft_putnbr_fd(n, 1);
//}