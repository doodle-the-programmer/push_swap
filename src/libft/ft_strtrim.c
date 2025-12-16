/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:40:30 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:51 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, end - start + 1);
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	// Test 1: Normal trimming
	result = ft_strtrim("   hello world   ", " he");
	printf("Test 1: '%s'\n", result);
	free(result);
	// Test 2: Trim multiple characters
	result = ft_strtrim("xxxhello worldxxx", "x");
	printf("Test 2: '%s'\n", result);
	free(result);
	// Test 3: Trim nothing
	result = ft_strtrim("hello world", "x");
	printf("Test 3: '%s'\n", result);
	free(result);
	// Test 4: Trim everything
	result = ft_strtrim("xxxxx", "x");
	printf("Test 4: '%s'\n", result);
	free(result);
	// Test 5: Empty string
	result = ft_strtrim("", " ");
	printf("Test 5: '%s'\n", result);
	free(result);
	// Test 6: Multiple trim characters
	result = ft_strtrim(" \t\nhello\n\t ", " \t\n");
	printf("Test 6: '%s'\n", result);
	free(result);
	return (0);
}
*/
