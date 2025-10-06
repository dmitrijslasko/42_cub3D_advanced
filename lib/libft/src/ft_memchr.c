/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:33:36 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 13:12:02 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memchr, memrchr, rawmemchr - scan memory for a character
// The  memchr()  function  scans the initial n bytes of the memory 
// area pointed to by s for the first instance of c.  
// Both c and the bytes of the memory area pointed to by s are 
// interpreted as unsigned char.
// The memrchr() function is like the memchr() function, except 
// that it searches backward from the end of the n bytes pointed to by s 
// instead of forward from the beginning.

#include "libft.h"

// scans through the memory to find a specified character. 
// returns the pointer to the position of the first occurence of that char
// inside the string
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char) c)
			return ((void *) ptr);
		ptr++;
	}
	return (NULL);
}
