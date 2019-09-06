/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:44:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/05 17:16:45 by jtaylor          ###   ########.fr       */
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

/*
** initial settings for the camera && the projection options
*/

static void	fdf_init_map_options(t_fdf *fdf)
{
	fdf->map.x_cord = 0;
	fdf->map.y_cord = 0;
	fdf->map.x_value = 1.00;
	fdf->map.y_angle = 0.5; // cos(M_PI / 3) / cos(pi / 3);
	fdf->map.z_angle = 0.25; // fdf->map.y_angle * sin(M_PI / 6) //.5 * .5
	// norm doesn't like nested ternary's :[
	fdf->map.zoom_value = (fdf->map.width > fdf->map.height) ? 
		WINDOW_WIDTH / fdf->map.width + INI_ZOOM :
		WINDOW_HEIGHT / fdf->map.height + INI_ZOOM;
	fdf->map.isometric_value = 1;
}

int		main(int ac, char **argv)
{
	t_fdf	*fdf;
	if (ac == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			fdf_putstrerr("malloc error", 1);
			;
		fdf_read_map(argv[1], fdf);
		fdf_init_map_options(fdf);
		fdf_init_mlx(fdf, argv[1]);
		//hook keys;
		//mlx_hook(fdf->mlx.window, 
		//mlx hook loop;
		//loop to run the function when a event is not taken ie(constatntly redraw the image);
		//takest the mlx pointer, a function pointer, and what argument to pass to the function
		//   mlx_loop_hook(fdf->mlx.init, fdf_draw, fdf);
		//what mlx uses to grab events;
		//test_display_grid(fdf);
		//test_simple_line(fdf);
		fdf_draw(fdf);
		mlx_loop(fdf->mlx.init);
	}
	else
		// print usage instructrions
		;
	return (0);
}
