/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:34:41 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:38:46 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memmove()  function  copies  n bytes from 
//memory area src to memory area dest.
// The memory areas may overlap: copying takes place as though the bytes in src
// are first copied into a temporary array that does not overlap src or dest, 
// and the bytes are then copied from the temporary array to dest.
// CHECKS:
// if dest = src or n == 0, no job needs to be done
// if both are NULL (no memory assigned)

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	if (ptr_src < ptr_dest && ptr_src + n > ptr_dest)
		while (n--)
			ptr_dest[n] = ptr_src[n];
	else
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
