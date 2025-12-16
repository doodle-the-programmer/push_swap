/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:03:04 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:07 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = get_num_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	// Test 1: Positive number
	result = ft_itoa(12345);
	printf("Test 1: '%s'\n", result);
	free(result);
	// Test 2: Negative number
	result = ft_itoa(-6789);
	printf("Test 2: '%s'\n", result);
	free(result);
	// Test 3: Zero
	result = ft_itoa(0);
	printf("Test 3: '%s'\n", result);
	free(result);
	// Test 4: INT_MIN
	result = ft_itoa(-2147483648);
	printf("Test 4: '%s'\n", result);
	free(result);
	// Test 5: INT_MAX
	result = ft_itoa(2147483647);
	printf("Test 5: '%s'\n", result);
	free(result);
	return (0);
}
*/
