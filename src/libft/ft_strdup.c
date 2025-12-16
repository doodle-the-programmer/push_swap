/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:27:42 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:07 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	// Test 1: Normal string
	result = ft_strdup("Hello World");
	printf("Test 1: '%s'\n", result);
	free(result);
	// Test 2: Empty string
	result = ft_strdup("");
	printf("Test 2: '%s'\n", result);
	free(result);
	// Test 3: Long string
	result = ft_strdup("This is a very long string for testing purposes");
	printf("Test 3: '%s'\n", result);
	free(result);
	return (0);
}
*/
