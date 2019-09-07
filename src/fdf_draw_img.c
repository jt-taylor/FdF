/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:45:57 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/06 19:52:44 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** not actually using the mlx_image functionality so don't '@' me ,
** i just didn't wanna rename the file
*/

static void		find_cordinates_inner_for_norm(t_fdf *fdf, int yt, int zt,
		int z)
{
	if (fdf->map.line_opt == 2 || fdf->map.line_opt == 3)
	{
		fdf->map.y1 = fdf->map.y_angle * ((yt + 1) - zt) * fdf->map.zoom_value;
		fdf->map.z1 = fdf->map.z_angle * ((yt + 1) + zt) * fdf->map.zoom_value;
		fdf->map.z1 -= fdf->map.map_values[z][fdf->map.norm + 1]
			* fdf->map.x_value;
		fdf->map.line_opt -= 2;
	}
	else if (fdf->map.line_opt == 1)
	{
		fdf->map.y1 = fdf->map.y_angle * (yt - (zt + 1)) * fdf->map.zoom_value;
		fdf->map.z1 = fdf->map.z_angle * (yt + (zt + 1)) * fdf->map.zoom_value;
		fdf->map.z1 -= fdf->map.map_values[z + 1][fdf->map.norm]
			* fdf->map.x_value;
		fdf->map.line_opt = 0;
	}
}

/*
** this does the math to convert the '3d' points into the 2d lines
** need to put in the zoom in and out
** doesn't center perfectly with specific window combinations
*/

static void		find_cordinates(t_fdf *fdf, int y, int z)
{
	int		yt;
	int		zt;

	while (fdf->map.line_opt)
	{
		yt = y - fdf->map.width / 2;
		zt = z - fdf->map.height / 2;
		fdf->map.y0 = fdf->map.y_angle * (yt - zt) * fdf->map.zoom_value;
		fdf->map.z0 = fdf->map.z_angle * (yt + zt) * fdf->map.zoom_value;
		fdf->map.z0 -= fdf->map.map_values[z][y] * fdf->map.x_value;
		fdf->map.norm = y;
		find_cordinates_inner_for_norm(fdf, yt, zt, z);
		fdf->map.y0 += (WINDOW_WIDTH / 2) + fdf->map.y_cord;
		fdf->map.y1 += (WINDOW_WIDTH / 2) + fdf->map.y_cord;
		fdf->map.z0 += (WINDOW_HEIGHT / 2) + fdf->map.x_cord;
		fdf->map.z1 += (WINDOW_HEIGHT / 2) + fdf->map.x_cord;
		line_bresenham(fdf->map.z0, fdf->map.y1, fdf->map.z1, fdf);
	}
}

void			fdf_draw(t_fdf *fdf)
{
	int		y;
	int		z;

	z = 0;
	while (fdf->map.height > z)
	{
		y = 0;
		while (fdf->map.width > y)
		{
			fdf->map.y0 = y;
			fdf->map.z0 = z;
			if (fdf->map.width > y + 1 || fdf->map.height > z + 1)
			{
				(fdf->map.width > y + 1) ? fdf->map.line_opt = 2 : 0;
				(fdf->map.height > z + 1) ? fdf->map.line_opt = 1 : 0;
				(fdf->map.width > y + 1 && fdf->map.height > z + 1) ?
					fdf->map.line_opt = 3 : 0;
				find_cordinates(fdf, y, z);
			}
			y++;
		}
		z++;
	}
}
