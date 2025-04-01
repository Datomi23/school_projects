/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 05:09:56 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/09/15 16:29:26 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define ERRR_MSG "It's./fractol mandelbrot OR\n\t\"./fractol julia <val_1> <val_2>"
#define WIDTH 800
#define HEIGHT 800
#define NERO             0x000000  
#define BIANCO           0xFFFFFF  
#define ROSSO            0xFF0000
#define VERDE            0x00FF00  
#define BLU              0x0000FF  
#define GIALLO           0xFFFF00  
#define CIANO            0x00FFFF  
#define MAGENTA          0xFF00FF  
#define GRIGIO           0x808080  
#define ARANCIONE        0xFFA500  
#define FUCSIA_ACIDO     0xFF1493  
#define VERDE_ACIDO      0x7FFF00  
#define VIOLA_PSICHEDELICO 0x9400D3
#define BLU_ELETTRICO    0x7DF9FF  
#define ARCOBALENO       0xFF00FF  
#define LIME_FLUO        0xCCFF00  
#define ROSA_NEON        0xFF6FFF  
#define ARANCIONE_FLUO   0xFF4500  

typedef struct s_img
{
    void *img_ptr;
    char *pixel_ptr;
    int bpp;
    int size_line;
    int endian;
}   t_img;

typedef struct s_fractal
{
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_img img;
    double vincolo;
    int max_iter;
    double shift_x;
    double shift_y;
    double zoom;
    double julia_x;
    double julia_y;
}   t_fractal;

typedef struct s_complex
{
    double x;
    double yi;

}   t_complex;

typedef struct s_math
{
    long intero;
	double decimale;
	int segno;
	double potenza;
}   t_math;

void fractal_init(t_fractal *fractal);
double scale_map(double unscaled_value, double new_min, double new_max, double old_max);
void fractal_render(t_fractal *fractal);
t_complex sum_cmplx(t_complex c1, t_complex c2);
t_complex square_cmplx(t_complex z);
int key_handle(int keysym, t_fractal *fractal);
int close_handle(t_fractal *fractal);
int mouse_handle(int button, int x, int y, t_fractal *fractal);
double ft_atoi_dbl(char *s);

#endif

/*
s_complex è una struttura che contiene due double x e y:
- x è la parte reale del numero complesso;
- yi è la parte immaginaria del numero complesso;

s_img è una struttura che contiene:
- img_ptr è un pointer a una struttura che contiene informazioni sull'immagine
- pixel_ptr è un pointer a un array di pixel
- bpp è il numero di bit per pixel
- size_line è il numero di byte per riga dell'immagine

s_fractal è una struttura che contiene:
- name è il nome del fractal
- mlx_connection è un pointer alla connessione con il server X
- mlx_window è un pointer alla finestra
- img è una struttura che contiene informazioni sull'immagine
- vincolo rappresenta l'ipotenusa dell'ideale triangolo rettangolo
  che ha come cateti la parte reale e la parte immaginaria del numero complesso
- max_iter è il numero massimo di iterazioni, da questo valore dipende la 
    qualità dell'immagine generata, e la velocità di rendering
*/