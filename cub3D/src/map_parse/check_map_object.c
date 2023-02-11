/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:40:52 by seojo             #+#    #+#             */
/*   Updated: 2023/02/11 17:51:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_object.h"

char	*compare_way(t_map *map, char *read_line, int *file_height, int fd)
{
	while (read_line != NULL && *read_line != '\n')
	{
		if (ft_strncmp("NO ", read_line, 3) == 0)
			map->no_path = check_path(read_line + 2);
		else if (ft_strncmp("SO ", read_line, 3) == 0)
			map->so_path = check_path(read_line + 2);
		else if (ft_strncmp("WE ", read_line, 3) == 0)
			map->we_path = check_path(read_line + 2);
		else if (ft_strncmp("EA ", read_line, 3) == 0)
			map->ea_path = check_path(read_line + 2);
		else
			err_exit("Insufficient image contents");
		safe_free(read_line);
		read_line = get_next_line(fd);
		(*file_height)++;
	}
	return (read_line);
}

char	*compare_color(t_map *map, int fd, char *read_line, int *file_height)
{
	while (read_line != NULL && *read_line != '\n')
	{
		if (ft_strncmp("F ", read_line, 2) == 0)
			map->floor = check_color(read_line + 1);
		else if (ft_strncmp("C ", read_line, 2) == 0)
			map->ceiling = check_color(read_line + 1);
		else
			err_exit("Insufficient color contents");
		safe_free(read_line);
		read_line = get_next_line(fd);
		(*file_height)++;
	}
	return (read_line);
}

char	*pass_newline(int fd, char *read_line, int *file_height)
{
	while (read_line != NULL && *read_line == '\n')
	{
		safe_free(read_line);
		read_line = get_next_line(fd);
		(*file_height)++;
	}
	return (read_line);
}

int	check_component(int fd, t_map *map)
{
	char	*read_line;
	int		file_height;

	file_height = 0;
	read_line = get_next_line(fd);
	read_line = pass_newline(fd, read_line, &file_height);
	read_line = compare_way(map, read_line, &file_height, fd);
	read_line = pass_newline(fd, read_line, &file_height);
	read_line = compare_color(map, fd, read_line, &file_height);
	read_line = pass_newline(fd, read_line, &file_height);
	if (read_line != NULL)
		safe_free(read_line);
	return (file_height);
}
