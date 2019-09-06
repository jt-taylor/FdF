/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:08:48 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/04 20:05:59 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** displays a grid of the values that it read from the input file  ,
** mostly used to debug what it read form the input file
*/

void		test_display_grid(t_fdf *fdf)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			mlx_string_put(fdf->mlx.init, fdf->mlx.window, (1024 / fdf->map.width * j + (1024 / fdf->map.width / 2)), (1024 / fdf->map.height * i + (1024 / fdf->map.height / 2)), ((int)255 + 2000 * fdf->map.map_values[i][j]), ft_itoa(fdf->map.map_values[i][j]));
			j++;
		}
		i++;
	}
}

void		test_simple_line(t_fdf *fdf)
{
	int		xstart;
	int		xend;
	int		ystart;
	int		yend;

	xstart = 100;
	ystart = 200;
	xend = 100;
	yend = 50;
	mlx_string_put(fdf->mlx.init, fdf->mlx.window, xstart, ystart, 0xFF0F00, "start pos");
	line_bresenham(xstart, ystart, xend, yend, fdf);
	line_bresenham(xstart * 2, ystart, xend * 3, yend, fdf);
	mlx_string_put(fdf->mlx.init, fdf->mlx.window, xend, yend, 0xFF0F00, "end pos");
}

void		test_simple_line_image(t_fdf *fdf)
{
	int		xstart;
	int		xend;
	int		ystart;
	int		yend;

	xstart = 100;
	ystart = 200;
	xend = 100;
	yend = 50;

	mlx_string_put(fdf->mlx.init, fdf->mlx.window, xstart, ystart, 0xFF0F00, "start pos");
	line_bresenham(xstart, ystart, xend, yend, fdf);
	mlx_string_put(fdf->mlx.init, fdf->mlx.window, xend, yend, 0xFF0F00, "end pos");
}
