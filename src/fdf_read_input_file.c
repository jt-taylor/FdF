/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_input_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:54:29 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/01 15:50:24 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_nbr(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			i++;
			count++;
			while (ft_isdigit(line[i]))
				i++;
		}
		else if (line[i] == ' ' || line[i] == '-')
			i++;
		else
			//errror invalid  char
			exit(1);
	}
	return (count);
}

static int	count_rows(t_fdf *fdf, char *file_name)
{
	int		fd;
	int		nbr_count;
	int		r;
	int		c;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		//error open ;
		;
	r = 0;
	c = 0;
	while (get_next_line(fd, &line))
	{
		if (!*line)
			break ;
		if ((nbr_count = count_nbr(line))) //count total nuimbers on this line) > c)
			c = nbr_count;
		(c == nbr_count) ? r++ : 0;//error invalid input ,
		free(line);
	}
	if (close(fd) < 0)
		// error closing file lul;
		;
	else if (!(fdf->map.width = c))
		// no columns lul ??
		;
	return (r);
}

static void	parse_line(int axis1, int axis2, char *line, t_fdf *fdf)
{
	int		i;
	char	**broken;

	if ((broken = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (broken[i])// && not out of bounds)
		{
			fdf->map.map_values[axis2][axis1] = ft_atoi(broken[i++]);
			axis1++;
		}
		free(broken);
	}
}

void		fdf_read_map(char *file_name, t_fdf *fdf)
{
	int		fd;
	int		axis1;
	int		axis2;
	char	*line;

	axis1 = 0;
	axis2 = 0;
	fdf->map.height = count_rows(fdf, file_name);
	if ((fd = open(file_name, O_RDONLY)) > -1)
	{
		if (!(fdf->map.map_values = (int **)malloc(sizeof(int *) * fdf->map.height)))
			//malloc error ;
			;
		while (get_next_line(fd, &line))
		{
			//parse_line_values
			if (!(fdf->map.map_values[axis2] = (int*)malloc(sizeof(int) * fdf->map.width)))
				//malloc error
				;
			parse_line(axis1, axis2 ,line, fdf);
			axis1 = 0;
			axis2++;
			free(line);
		}
	}
	else
		//error opening file
		;
}
