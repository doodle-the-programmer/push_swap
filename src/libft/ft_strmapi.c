/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:59:57 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 18:19:14 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>

char	to_upper_test(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	add_index(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*result;

	// Test 1: Convert to uppercase
	result = ft_strmapi("hello world", to_upper_test);
	printf("Test 1: '%s'\n", result);
	free(result);
	// Test 2: Add index to each char
	result = ft_strmapi("aaa", add_index);
	printf("Test 2: '%s'\n", result);
	free(result);
	// Test 3: Empty string
	result = ft_strmapi("", to_upper_test);
	printf("Test 3: '%s'\n", result);
	free(result);
	return (0);
}
*/
