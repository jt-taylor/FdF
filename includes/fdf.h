/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:45:12 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/01 15:16:11 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#ifndef FDF_H
# define FDF_H

typedef struct	s_minilibx
{
	void	*init;
	void	*window;
	void	*img;
}				t_minilibx;

typedef struct	s_map
{
	int		**map_values;
	int		height; // how many rows
	int		width; // how many numbers in each row
}				t_map;

typedef struct	s_image
{
	int		placeholder;
}				t_image;

typedef struct	s_fdf
{
	t_minilibx	mlx;
	t_map		map;
	t_image		img;
}				t_fdf;

void	fdf_read_map(char *file_name, t_fdf *fdf);
#endif
