/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:38:59 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/03/01 16:22:56 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(long n, char spfr)
{
	t_list	var;

	var.cnt = 0;
	if (n == INT_MIN)
		return (var.cnt += ft_putstr("-2147483648"));
	if (n < 0)
	{
		var.cnt += ft_putchar('-');
		var.cnt += ft_putnbr_base(-n, 10, spfr);
	}
	else
		var.cnt += ft_putnbr_base(n, 10, spfr);
	return (var.cnt);
}

int	print_unsigned(long n, int base)
{
	t_list	var;

	var.cnt = 0;
	if (n >= 0 && n <= 4294967295)
		var.cnt += ft_putnbr_base(n, base, 'd');
	else
		var.cnt += ft_putchar('0');
	return (var.cnt);
}
