/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:02 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/27 15:27:25 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	// Test 1: Normal substring
	result = ft_substr("Hello World", 6, 5);
	printf("Test 1: '%s'\n", result);
	free(result);
	// Test 2: Start at 0
	result = ft_substr("Hello", 0, 3);
	printf("Test 2: '%s'\n", result);
	free(result);
	// Test 3: Start beyond string length
	result = ft_substr("Hello", 20, 5);
	printf("Test 3: '%s'\n", result);
	free(result);
	// Test 4: Len longer than remaining string
	result = ft_substr("Hello", 2, 100);
	printf("Test 4: '%s'\n", result);
	free(result);
	// Test 5: Empty string
	result = ft_substr("", 0, 5);
	printf("Test 5: '%s'\n", result);
	free(result);
	return (0);
}
*/
