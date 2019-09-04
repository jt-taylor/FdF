/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:44:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/03 19:54:04 by jtaylor          ###   ########.fr       */
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

void	fdf_putstrerr(char *str, int err_code)
{
	ft_dprintf(2, "%s\nErr code = %d\n", str, err_code);
	exit(err_code);
}

static void		fdf_init_mlx(t_fdf *fdf, char *win_name)
{
	fdf->mlx.init = mlx_init();
//	fdf->mlx.window = mlx_new_window(fdf->mlx.init, //win width, //win height, win_name);
	fdf->mlx.window = mlx_new_window(fdf->mlx.init, 1024, 1024, win_name);
}

// innit the setitngs for the display window ie color windowsize

static void	fdf_init_map_options(t_fdf *fdf)
{
	//fill me in dummy
	(void)fdf;
}

int		main(int ac, char **argv)
{
	t_fdf	*fdf;
	if (ac == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			//return error
			;
		//read map;
		//this reads the input file into a 2d int array ;
		fdf_read_map(argv[1], fdf);
		// init map struct;
		fdf_init_map_options(fdf);
		//init mlx mindow;
		fdf_init_mlx(fdf, argv[1]);
		//hook keys;
		//mlx_hook(fdf->mlx.window, 
		//mlx hook loop;
		//loop to run the function when a event is not taken ie(constatntly redraw the image);
		//takest the mlx pointer, a function pointer, and what argument to pass to the function
		//   mlx_loop_hook(fdf->mlx.init, fdf_draw, fdf);
		//what mlx uses to grab events;
		test_display_grid(fdf);
		mlx_loop(fdf->mlx.init);
	}
	else
		// print usage instructrions
		;
	return (0);
}
