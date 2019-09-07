/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:34:23 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/06 20:05:20 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** this is the .h referenced in the mlx_loop man page
** #include <keysymdef.h>
*/

/*
** colors go from 0 to 0xFFFFE
*/

static void		fdf_rand_color(t_fdf *fdf)
{
	fdf->map.color = rand() % 0xFFFFFF;
	mlx_clear_window(fdf->mlx.init, fdf->mlx.window);
	fdf_draw(fdf);
}

/*
** 0x35 == escape;	exit
** 0x31 == space;	random color between 0x00 && 0xFFFFFF
** 0x21 == '[';		thes two change the zoom
** 0x1E == ']';		^^
** 0x02 == 'D'		debug mode to show the map values
** 0x28 == 'k';		increase the andle
** 0x25 == 'j';		decrease the angle
*/

int				fdf_keypress(int key_code, t_fdf *fdf)
{
	(void)fdf;
	if (key_code == 0x35)
		exit(0);
	else if (key_code == 0x31)
		fdf_rand_color(fdf);
	else if (key_code == 0x1E)
		fdf->map.zoom_value += 1;
	else if (key_code == 0x21)
		fdf->map.zoom_value += (fdf->map.zoom_value > 1) ? -1 : 1;
	else if (key_code == 0x02)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.window);
		test_display_grid(fdf);
		return (0);
	}
	else if (key_code == 0x28)
		fdf->map.z_angle += .1;
	else if (key_code == 0x25)
		fdf->map.z_angle -= .1;
	mlx_clear_window(fdf->mlx.init, fdf->mlx.window);
	fdf_draw(fdf);
	return (0);
}
