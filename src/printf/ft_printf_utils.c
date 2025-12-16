/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:59:08 by gpatrici          #+#    #+#             */
/*   Updated: 2025/11/10 16:29:34 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_lowercase(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_put_hex_lowercase(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + ft_put_hex_lowercase(n));
}

int	ft_put_unbr(unsigned long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_put_unbr(n / 10);
	c = (char)('0' + (n % 10));
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_long(long nbr)
{
	int				count;
	unsigned long	n;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		n = (unsigned long)(-nbr);
	}
	else
		n = (unsigned long)nbr;
	count += ft_put_unbr(n);
	return (count);
}
