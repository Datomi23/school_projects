/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:34:29 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/03/01 16:24:46 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
	int		cnt;
	char	*dic;
}		t_list;
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(long n, int base, char spfr);
int	print_unsigned(long n, int base);
int	print_int(long n, char spfr);
int	print_pointer(long n, int base);
int	print_format(char spfr, va_list ap);
int	ft_printf(const char *format, ...);
