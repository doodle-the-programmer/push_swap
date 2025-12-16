/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:59:18 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 13:29:28 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	scan_c(char **fmt_i, va_list *ap)
{
	int	counter;

	counter = 0;
	if (**fmt_i == '%' && *(*fmt_i + 1))
	{
		if (*(*fmt_i + 1) == 's')
			counter += ft_putstr(va_arg(*ap, char *));
		else if (*(*fmt_i + 1) == 'c')
			counter += ft_putchar((char)va_arg(*ap, int));
		else if (*(*fmt_i + 1) == 'p')
			counter += ft_putptr(va_arg(*ap, void *));
		else if (*(*fmt_i + 1) == 'd' || *(*fmt_i + 1) == 'i')
			counter += ft_putnbr_long(va_arg(*ap, int));
		else if (*(*fmt_i + 1) == 'u')
			counter += ft_put_unbr(va_arg(*ap, unsigned int));
		else if (*(*fmt_i + 1) == 'x')
			counter += ft_put_hex_lowercase(va_arg(*ap, unsigned int));
		else if (*(*fmt_i + 1) == 'X')
			counter += ft_put_hex_uppercase(va_arg(*ap, unsigned int));
		else if (*(*fmt_i + 1) == '%')
			counter += ft_putchar('%');
		*fmt_i += 2;
		return (counter);
	}
	return (write(1, (*fmt_i)++, 1));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		printed;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	printed = 0;
	while (*fmt)
		printed += scan_c((char **)&fmt, &ap);
	va_end(ap);
	return (printed);
}
