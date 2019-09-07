/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:45:12 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/06 19:54:57 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

/*
** macros
*/
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define INI_ZOOM 0

typedef struct	s_minilibx
{
	void	*init;
	void	*window;
	void	*img;
}				t_minilibx;

typedef struct	s_map
{
	int		**map_values;
	int		height;
	int		width;
	int		x_cord;
	int		y_cord;
	int		y0;
	int		y1;
	int		z0;
	int		z1;
	int		zoom_value;
	int		isometric_value;
	double	x_value;
	double	y_angle;
	double	z_angle;
	int		color;
	int		line_opt;
	int		norm;
}				t_map;

typedef struct	s_line_alg
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err1;
	int		err2;
}				t_line_alg;

typedef struct	s_fdf
{
	t_minilibx	mlx;
	t_map		map;
	t_line_alg	line;
}				t_fdf;

/*
** fdf_read_input_file.c
*/

void			fdf_read_map(char *file_name, t_fdf *fdf);

/*
** fdf_draw_img.c
*/

void			fdf_draw(t_fdf *fdf);

/*
** fdf_keypress.c
*/
int				fdf_keypress(int key_code, t_fdf *fdf);

/*
** main.c
*/

void			fdf_putstrerr(char *str, int err_code);

/*
** for debugging
*/

void			test_display_grid(t_fdf *fdf);
void			line_bresenham(int ystart, int xfinal, int	yfinal,
		t_fdf *fdf);

#endif
