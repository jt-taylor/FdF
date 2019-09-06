/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:34:24 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/05 11:41:34 by jtaylor          ###   ########.fr       */
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
** also this link
** https://unionassets.com/blog/algorithm-brezenhema-and-wu-s-line-299
*/

/*
** I decided to use the mlx_pixel_put instead of the mlx_image functionality
** so I don't care about the gradiant that using xaolin would give us
*/

/*
** this is a implementaiton of the bresenham alg,
**
** it draws a line from (x-start, y-start) -> (x-end, y-end) into
** the mlx window with mlx_pixel_put
**
** to modify this to use the mlx image functions change mlx_pixel_put function
*/

void		line_bresenham(int xstart, int ystart, int xfinal, int yfinal,
		t_fdf *fdf)
{
	fdf->line.dx = abs(xfinal - xstart);
	fdf->line.sx = (xstart < xfinal) ? 1 : -1;
	fdf->line.dy = abs(yfinal - ystart);
	fdf->line.sy = (ystart < yfinal) ? 1 : -1;
	fdf->line.err1 = (fdf->line.dx > fdf->line.dy) ? fdf->line.dx / 2 : fdf->line.dy / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.window, xstart, ystart, 0xFFFF00);
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
