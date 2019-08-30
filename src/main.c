/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:44:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/30 11:55:37 by jtaylor          ###   ########.fr       */
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
	mlx_pixel_put(mlx_pointer, mlx_window_pointer, 250, 250, (int)255);
	mlx_string_put(mlx_pointer, mlx_window_pointer, 255, 250, (int)255, "Neato burrito");
	mlx_loop(mlx_pointer);
}
