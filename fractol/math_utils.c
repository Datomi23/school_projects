/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 04:46:51 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/09/15 18:36:05 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_map(double unscld, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscld - 0) / (old_max - 0) + new_min);
}

t_complex	sum_cmplx(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.x = c1.x + c2.x;
	res.yi = c1.yi + c2.yi;
	return (res);
}

t_complex	square_cmplx(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.yi * z.yi);
	res.yi = 2 * z.x * z.yi;
	return (res);
}

double	ft_atoi_dbl(char *s)
{
	t_math	convert;

	convert.intero = 0;
	convert.decimale = 0;
	convert.segno = 1;
	convert.potenza = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			convert.segno = -convert.segno;
	while (*s != '.' && *s != '\0')
		convert.intero = convert.intero * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s != '\0')
	{
		convert.potenza = convert.potenza / 10;
		convert.decimale = convert.decimale + (*s++ - '0') * convert.potenza;
	}
	return ((convert.intero + convert.decimale) * convert.segno);
}

/* map usa l'interpolazione lineare per mappare un valore da un intervallo
a un altro sum_cmplx somma due numeri complessi
square_cmplx calcola il quadrato di un numero complesso: 
in questo caso res.x è la parte REALE del quadrato di z,
mentre res.yi ne rappresenta la parte IMMAGINARIA.
*/