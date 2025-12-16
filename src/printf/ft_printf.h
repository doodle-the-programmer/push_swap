/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:57:27 by gpatrici          #+#    #+#             */
/*   Updated: 2025/11/04 22:54:02 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_putptr(void *ptr);
int	ft_put_unbr(unsigned long nbr);
int	ft_putnbr_long(long nbr);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_put_mem(unsigned long n);
int	ft_put_hex_uppercase(unsigned long n);
int	ft_put_hex_lowercase(unsigned long n);
int	ft_printf(const char *fmt, ...);

#endif
