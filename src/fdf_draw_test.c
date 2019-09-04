/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:08:48 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/03 20:03:04 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			mlx_string_put(fdf->mlx.init, fdf->mlx.window, (1024 / fdf->map.width * j), (1024 / fdf->map.height * i), ((int)255 + 2000 * fdf->map.map_values[i][j]), ft_itoa(fdf->map.map_values[i][j]));
			j++;
		}
		i++;
	}
	mlx_string_put(fdf->mlx.init, fdf->mlx.window, 512, 512, 255, "y you no work");
}
