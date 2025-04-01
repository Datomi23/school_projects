/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:01:31 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/03/01 16:23:50 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	t_list	var;

	var.cnt = 0;
	if (!s)
		return (ft_putstr("(null)"));
	else
	{
		while (*s)
			var.cnt += ft_putchar(*s++);
		return (var.cnt);
	}
}

int	ft_putnbr_base(long n, int base, char spfr)
{
	t_list	var;

	var.dic = "0123456789abcdef";
	var.cnt = 0;
	if (n < base)
	{
		if (spfr == 'X' && n % base > 9)
			var.cnt += ft_putchar(var.dic[n] - 32);
		else
			var.cnt += ft_putchar(var.dic[n]);
	}
	else
	{
		var.cnt += ft_putnbr_base(n / base, base, spfr);
		if (spfr == 'X' && n % base > 9)
			var.cnt += ft_putchar(var.dic[n % base] - 32);
		else
			var.cnt += ft_putchar(var.dic[n % base]);
	}
	return (var.cnt);
}

int	print_pointer(long n, int base)
{
	t_list	var;

	var.cnt = 0;
	if (n == 0)
	{
		var.cnt += ft_putstr("(nil)");
		return (var.cnt);
	}
	if ((long)n == LONG_MIN)
		return (ft_putstr("0x8000000000000000"));
	if ((long)n == LONG_MAX)
		return (ft_putstr("0x7fffffffffffffff"));
	if ((unsigned long)n == ULONG_MAX)
		return (ft_putstr("0xffffffffffffffff"));
	if (n == -ULONG_MAX)
		return (ft_putstr("0x1"));
	if (n < 0)
		n = -n;
	var.cnt += ft_putstr("0x");
	var.cnt += ft_putnbr_base(n, base, 'x');
	return (var.cnt);
}

int	print_format(char spfr, va_list ap)
{
	t_list	var;

	var.cnt = 0;
	if (spfr == 'c')
		var.cnt += ft_putchar(va_arg(ap, int));
	else if (spfr == 's')
		var.cnt += ft_putstr(va_arg(ap, char *));
	else if (spfr == 'd' || spfr == 'i')
		var.cnt += print_int(va_arg(ap, int), spfr);
	else if (spfr == 'x')
		var.cnt += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, spfr);
	else if (spfr == 'X')
		var.cnt += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, spfr);
	else if (spfr == 'p')
		var.cnt += print_pointer((long)va_arg(ap, void *), 16);
	else if (spfr == 'u')
		var.cnt += print_unsigned((long)va_arg(ap, unsigned int), 10);
	else
		var.cnt += write(1, &spfr, 1);
	return (var.cnt);
}
