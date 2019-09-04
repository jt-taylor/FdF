/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:34:24 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/04 15:12:08 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** So there are a few line drawing algorithms that we can use for this
** both work on the same principle ,
** Bresenham is the simplest and just calculates the pixel that is the closest
**		match to where you are on the line;
**		this alg is o[ptomised to only use addition to check the pixels;
**		need to hanlde the vector and slope before the alg and swap the inputs
**		around if needed
** Xaolin wu's algo
** 		uses a bunch of floats but also calculates the color gradient for
** 		the pixel based on the 'error' from the true line;
**
** I'm sure that you want more info so check the fdf cookbook on intra ,
** And look at the libftgfx github --> has a ton of links for all of the 
** graphics projects ,the link at the moment https://github.com/qst0/ft_libgfx
** // I know it's bad to link to things that I don't own / maintain but
** // I'm sure that you can deal with it
*/

void		line_bresenham(int xstart, int ystart, int xfinal, int yfinal,
		t_fdf *fdf)
{
	fdf->line.dx = abs(xfinal - xstart);
	fdf->line.sx = (xstart < xfinal) ? 1 : -1;
	fdf->line.dy = abs(yfinal - ystart);
	fdf->line.sy = (ystart < yfinal) ? 1 : -1;
	fdf->line.err1 = (fdf->line.dx > fdf->line.dy) ? fdf->line.dx / 2 : fdf->line.dy / 2;
	//grr infinite loop bad
	while (1)
	{
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.window, xstart, ystart, 0xFFFF00);//color
		if (xstart == xfinal && ystart == yfinal)
			break ;
		fdf->line.err2 = fdf->line.err1;
		if (fdf->line.err2 > -fdf->line.dx)
		{
			fdf->line.err1 -= fdf->line.dy;
			(xstart != xfinal) ? xstart += fdf->line.sx : 0;
		}
		if (fdf->line.err2 < fdf->line.dy)
		{
			fdf->line.err1 += fdf->line.dx;
			(ystart != yfinal) ? ystart += fdf->line.sy : 0;
		}
	}
}
