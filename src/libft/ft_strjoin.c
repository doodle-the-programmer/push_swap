/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:36:21 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:07 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	res[0] = '\0';
	ft_strlcat(res, s1, total_len + 1);
	ft_strlcat(res, s2, total_len + 1);
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	// Test 1: Normal join
	result = ft_strjoin("Hello ", "World");
	printf("Test 1: '%s'\n", result);
	free(result);
	// Test 2: Empty strings
	result = ft_strjoin("", "Hello");
	printf("Test 2: '%s'\n", result);
	free(result);
	// Test 3: Both empty
	result = ft_strjoin("", "");
	printf("Test 3: '%s'\n", result);
	free(result);
	// Test 4: Long strings
	result = ft_strjoin("This is a long string ", "and another long string");
	printf("Test 4: '%s'\n", result);
	free(result);
	return (0);
}
*/
