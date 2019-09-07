/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:44:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/06 20:09:53 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** read the included man for minilibx , takes a minute due to how it is set up
** but it does go over everything that it needs too to be useful
*/

void		fdf_putstrerr(char *str, int err_code)
{
	ft_dprintf(2, "%s\nErr code = %d\n", str, err_code);
	exit(err_code);
}

static void	fdf_init_mlx(t_fdf *fdf, char *win_name)
{
	fdf->mlx.init = mlx_init();
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
	fdf->map.y_angle = 0.5;
	fdf->map.z_angle = 0.25;
	fdf->map.line_opt = 0;
	fdf->map.zoom_value = (fdf->map.width > fdf->map.height) ?
		WINDOW_WIDTH / fdf->map.width + INI_ZOOM :
		WINDOW_HEIGHT / fdf->map.height + INI_ZOOM;
	fdf->map.isometric_value = 1;
	fdf->map.color = 0xFFFF00;
}

int			main(int ac, char **argv)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			fdf_putstrerr("malloc error", 1);
		fdf_read_map(argv[1], fdf);
		fdf_init_map_options(fdf);
		fdf_init_mlx(fdf, argv[1]);
		mlx_key_hook(fdf->mlx.window, fdf_keypress, fdf);
		fdf_draw(fdf);
		mlx_loop(fdf->mlx.init);
	}
	else
		ft_printf("how to use\n\t\'./fdf\' [path to map file]\n");
	return (0);
}
