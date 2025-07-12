/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:35:43 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:34:53 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RETURN for strlcat() = the initial length of dst plus the
// length of src.
// if strlcat() traverses size characters without finding a NUL, 
// the length of the string 
// is considered to be size and the destination string will not
// be NUL-terminated 
// (since there was no space for the NUL). This keeps strlcat()
// from running off 
// the end of a string. In practice this should not happen 
// (as it means that either size is incorrect or that 
//dst is not a proper C string). 
// The check exists to prevent potential security problems inincorrect code.

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && (i + j) < (size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (src_len + dst_len);
}

//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//     char src[] = "1234567890";
//     char dest[] = "abcd";
//     printf("\nSRC before the function call: %s\n", src);
//     printf("DEST before the function call: %s\n", dest);
//     printf("----------------------------------------------------\n"); 
//     printf("LEN (SRC + DEST): %zu\n", ft_strlcat(dest, src, 10));
//     printf("SRC after the function call: %s\n", src);
//     printf("DEST after the function call: %s\n\n", dest);
// }