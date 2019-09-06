/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:45:57 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/05 17:29:08 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** not actually using the mlx_image functionality so don't '@' me ,
** i just didn't wanna rename the file
*/


/*
** this should do all the math to simulate the camera angle &&
** projection ;
** I can either make this two functions one for each axis or 
** make one probably unreadable too long for norminette comment
*/

static void		find_cordinates(t_fdf *fdf, int line_opt, int y, int z)
{
	int		yt;
	int		zt;

	while (line_opt)
	{
		yt = y - fdf->map.width / 2;
		zt = z - fdf->map.height / 2;
		fdf->map.y0 = fdf->map.y_angle * (yt - zt) * fdf->map.zoom_value;
		fdf->map.z0 = fdf->map.z_angle * (yt + zt) * fdf->map.zoom_value;
		fdf->map.z0 -= fdf->map.map_values[z][y] * fdf->map.x_value;
		if (line_opt == 2 || line_opt == 3)
		{
			fdf->map.y1 = fdf->map.y_angle * ((yt + 1) - zt) * fdf->map.zoom_value;
			fdf->map.z1 = fdf->map.z_angle * ((yt + 1) + zt) * fdf->map.zoom_value;
			fdf->map.z1 -= fdf->map.map_values[z][y + 1] * fdf->map.x_value;
			line_opt -= 2;
		}
		else if (line_opt == 1)
		{
			fdf->map.y1 = fdf->map.y_angle * (yt - (zt + 1)) * fdf->map.zoom_value;
			fdf->map.z1 = fdf->map.z_angle * (yt + (zt + 1)) * fdf->map.zoom_value;
			fdf->map.z1 -= fdf->map.map_values[z + 1][y] * fdf->map.x_value;
			line_opt = 0;
		}
		fdf->map.y0 += (WINDOW_WIDTH / 2) + fdf->map.y_cord;
		fdf->map.y1 += (WINDOW_WIDTH / 2) + fdf->map.y_cord;
		fdf->map.z0 += (WINDOW_HEIGHT / 2) + fdf->map.x_cord;
		fdf->map.z1 += (WINDOW_HEIGHT / 2) + fdf->map.x_cord;
		line_bresenham(fdf->map.z0, fdf->map.y0, fdf->map.z1, fdf->map.y1, fdf);
	}
}

void		fdf_draw(t_fdf *fdf)
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
				if (fdf->map.width > y + 1 && fdf->map.height > z + 1)
					find_cordinates(fdf, 3, y, z);
				else if (fdf->map.width > y + 1)
					find_cordinates(fdf, 2, y, z);
				else if (fdf->map.height > z + 1)
					find_cordinates(fdf, 1, y, z);
			}
			y++;
		}
		z++;
	}
}
