/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:55:40 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/06 20:04:40 by jtaylor          ###   ########.fr       */
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
			mlx_string_put(fdf->mlx.init, fdf->mlx.window,
		(1024 / fdf->map.width * j + (1024 / fdf->map.width / 2)),
		(1024 / fdf->map.height * i + (1024 / fdf->map.height / 2)),
		((int)255 + 2000 * fdf->map.map_values[i][j]),
		ft_itoa(fdf->map.map_values[i][j]));
			j++;
		}
		i++;
	}
}
