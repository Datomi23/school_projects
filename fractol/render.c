/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:29:19 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/09/15 18:34:22 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_push(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	ft_mandle_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->yi = z->yi;
	}
	else
	{
		c->x = fractal->julia_x;
		c->yi = fractal->julia_y;
	}
}

static void	gest_pxl(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colore;

	i = 0;
	z.x = (scale_map(x, -2.0, 2.0, WIDTH) * fractal->zoom + fractal->shift_x);
	z.yi = (scale_map(y, 2.0, -2.0, HEIGHT) * fractal->zoom + fractal->shift_y);
	ft_mandle_or_julia(&z, &c, fractal);
	while (i < fractal->max_iter)
	{
		z = sum_cmplx(square_cmplx(z), c);
		if (((z.x * z.x) + (z.yi * z.yi)) > fractal->vincolo)
		{
			colore = scale_map(i, MAGENTA, CIANO, fractal->max_iter);
			pixel_push(x, y, &fractal->img, colore);
			return ;
		}
		++i;
	}
	pixel_push(x, y, &fractal->img, BIANCO);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			gest_pxl(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

/* è necessario scalare i pixel da l'intervallo 800 x 800 a -2 x +2
intervallo in cui sono contenute le coordinate del set di Mandelbrot
		0 -> 800     -2 -> +2
		----------- -----------
		|         | |         |
		|         | |         |
		|         | |         |
		|         | |         |
		----------- -----------
   funzione set di Mandelbrot:
   z =  z^2 + c

   c.x e c.yi sono le coordinate del pixel che stiamo disegnando
   messe in "scala" tra -2 e +2 per soddisfare le coordinate del
   set di Mandelbrot
*/
