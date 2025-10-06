/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:36:12 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 18:34:35 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// #include <stdio.h>
// #include <assert.h>
// // Unit tests
// void test_ft_strlen() {
//     // Test case 1: Normal string
//     assert(ft_strlen("hello") == 5);
//     printf("Test case 1 passed\n");

//     // Test case 2: Empty string
//     assert(ft_strlen("") == 0);
//     printf("Test case 2 passed\n");

//     // Test case 3: String with spaces
//     assert(ft_strlen("hello world") == 11);
//     printf("Test case 3 passed\n");

//     // Test case 4: String with special characters
//     assert(ft_strlen("hello\nworld") == 11);
//     printf("Test case 4 passed\n");

//     // Test case 5: String with null character in the middle
//     assert(ft_strlen("hello\0world") == 5);
//     printf("Test case 5 passed\n");

//     // Test case 6: Long string
//     assert(ft_strlen("This is a very long string used 
//		for testing purposes.") == 53);
//     printf("Test case 6 passed\n");
// }

// int main() {
//     test_ft_strlen();
//     printf("All test cases passed!\n");
//     return 0;
// }