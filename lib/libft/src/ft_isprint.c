/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:00:31 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:40:35 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// determines if the input char parameter is printable 
// (32 = space; 126 = ~; 127 is DEL (not printable))
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
