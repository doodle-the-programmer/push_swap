/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:28:57 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/27 15:29:46 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[20] = "Hello World";
	char	str2[20] = "Hello World";
	char	src[] = "Test";
	char	dest[10];

	// Test 1: Overlapping - shift right
	printf("Before: %s\n", str1);
	ft_memmove(str1 + 2, str1, 8);
	printf("After shift right: %s\n", str1);
	// Test 2: Overlapping - shift left
	printf("\nBefore: %s\n", str2);
	ft_memmove(str2, str2 + 2, 8);
	printf("After shift left: %s\n", str2);
	// Test 3: Non-overlapping
	ft_memmove(dest, src, 5);
	printf("\nNon-overlapping: %s\n", dest);
	return (0);
}
*/
