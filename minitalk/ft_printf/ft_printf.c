/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:01:01 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/02/28 12:25:42 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	var;

	va_start(ap, format);
	var.cnt = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			var.cnt += print_format(*++format, ap);
		else
			var.cnt += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (var.cnt);
}
