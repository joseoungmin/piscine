/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:32:41 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 12:55:48 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_color.h"

char	*split_color(char *read_line, int *color)
{
	int	i;

	read_line = pass_space(read_line);
	*color = ft_atoi(read_line);
	i = 1;
	while (i < *color)
	{
		read_line++;
		i *= 10;
	}
	while (*read_line && ft_isdigit(*read_line) == 0 && \
			*read_line != '-' && *read_line != '+')
		read_line++;
	return (read_line);
}

int	check_color(char *read_line)
{
	int	color[3];

	color[RED] = 0;
	color[GREEN] = 0;
	color[BLUE] = 0;
	read_line = pass_space(read_line);
	check_line(read_line);
	read_line = split_color(read_line, &color[RED]);
	read_line = split_color(read_line, &color[GREEN]);
	read_line = split_color(read_line, &color[BLUE]);
	if (color[RED] < 0 || color[GREEN] < 0 || color[BLUE] < 0)
		err_exit("color is under 0");
	else if (color[RED] > 255 || color[GREEN] > 255 || color[BLUE] > 255)
		err_exit("color is over 255");
	return (color[RED] << 16 | color[GREEN] << 8 | color[BLUE]);
}

int	check_color_argu(t_world *world, char *read_line, int fc)
{
	if (fc == C && world->ceiling != -1)
		err_exit("Too many color arguments");
	if (fc == F && world->floor != -1)
		err_exit("Too many color arguments");
	return (check_color(read_line));
}
