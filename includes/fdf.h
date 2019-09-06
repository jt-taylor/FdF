/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:45:12 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/05 17:17:49 by jtaylor          ###   ########.fr       */
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
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define INI_ZOOM 2

typedef struct	s_minilibx
{
	void	*init;
	void	*window;
	void	*img;
}				t_minilibx;

typedef struct	s_map
{
	int		**map_values; // matrix built from the input file
	int		height; // how many rows
	int		width; // how many numbers in each row
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
}				t_map;

typedef struct s_line_alg
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

void		fdf_draw(t_fdf *fdf);

/*
** main.c
*/

void			fdf_putstrerr(char *str, int err_code);

//testing remove me later
void		test_display_grid(t_fdf *fdf);
void		line_bresenham(int xstart, int ystart, int xfinal, int	yfinal,
		t_fdf *fdf);
void		test_simple_line(t_fdf *fdf);
void		test_display_line_image(t_fdf *fdf);

#endif
