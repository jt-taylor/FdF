/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:44:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/01 15:02:59 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** example :
**	void	*mlx_pointer;
**	void	*mlx_window_pointer;
**
**	(void)ac;
**	(void)argv;
**	mlx_pointer = mlx_init();
**	mlx_window_pointer = mlx_new_window(mlx_pointer, 500, 500, "mlx_test_window");
**	mlx_pixel_put(mlx_pointer, mlx_window_pointer, 250, 250, (int)255);
**	mlx_string_put(mlx_pointer, mlx_window_pointer, 255, 250, (int)255, "Neato burrito");
**	mlx_loop(mlx_pointer);
*/

int		main(int ac, char **argv)
{
	t_fdf	*fdf;
	if (ac == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			//return error
			;
		//read map;
		fdf_read_map(argv[1], fdf);
		// init map struct;
		//init mlx mindow;
		//hook keys;
		//mlx hook loop;
		//mlx display loop;
	}
	else
		// print usage instructrions
		;
	return (0);
}
