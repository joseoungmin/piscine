/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:45:43 by seojo             #+#    #+#             */
/*   Updated: 2023/02/11 17:46:48 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_file_color.h"

char	*split_filename(char *line)
{
	int		idx;
	char	*filename;

	idx = 0;
	while (line[idx] && line[idx] != ' ' && line[idx] != '\n')
		idx++;
	filename = ft_substr(line, 0, idx);
	if (filename == NULL)
		err_exit("split_filename : malloc fail");
	return (filename);
}

char	*check_path(char *read_line)
{
	int		fd;
	char	*filename;

	read_line = pass_space(read_line);
	if (*read_line == '\n' || *read_line == '\0')
		err_exit("Invalid path object");
	filename = split_filename(read_line);
	fd = ft_open(filename);
	close(fd);
	return (filename);
}

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
