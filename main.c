/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:44:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/29 18:50:09 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **argv)
{
	void	*mlx_pointer;
	void	*mlx_window_pointer;

	(void)ac;
	(void)argv;
	mlx_pointer = mlx_init();
	mlx_window_pointer = mlx_new_window(mlx_pointer, 500, 500, "mlx_test_window");
	mlx_loop(mlx_pointer);
	
	//mlx_pixel_put(mlx_pointer, mlx_window_pointer, 50, 50, 0xFF0000);
}
