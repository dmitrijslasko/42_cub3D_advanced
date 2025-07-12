/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:00:25 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:40:40 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// determines if the input char parameter is ASCII (0-127)
int	ft_isascii(int c)
{
	if (c == 0)
		return (1);
	if (c > 0 && c <= 127)
		return (c);
	return (0);
}
