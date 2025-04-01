/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:36:06 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/09/15 18:34:51 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (4 == ac)
		{
			fractal.julia_x = ft_atoi_dbl(av[2]);
			fractal.julia_y = ft_atoi_dbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot or julia val_1 val_2\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

// creare mandelbrot e Julia set
