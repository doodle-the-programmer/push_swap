/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:03:46 by gpatrici          #+#    #+#             */
/*   Updated: 2025/11/04 22:50:20 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_mem(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	count += write(1, "0x", 2);
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_put_hex_lowercase(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_put_hex_uppercase(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_put_hex_uppercase(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
