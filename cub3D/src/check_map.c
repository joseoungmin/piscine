/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:46 by seojo             #+#    #+#             */
/*   Updated: 2023/01/13 20:52:04 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

#include <stdio.h>

char	*check_path(char *read_line)
{
	int	fd;

	while (ft_isspace(*read_line) == TRUE)
		read_line++;
	fd = open(read_line, O_RDONLY);
	if (errno == 2)
		err_exit("No such file or directory");
	else if (errno == 13)
		err_exit("Permission denied");
	else if (fd < 0)
		err_exit("File open error");
	close(fd);
	return (ft_strdup(read_line));
}

char	*split_colar(char *read_line, int *colar)
{
	int	i;

	while (ft_isspace(*read_line) == TRUE)
		read_line++;
	*colar = ft_atoi(read_line);
	i = 1;
	while (i < *colar)
	{
		read_line++;
		i *= 10;
	}
	while (*read_line && ft_isdigit(*read_line) == 0)
		read_line++;
	return(read_line);
}

int	check_colar(char *read_line)
{
	int	colar[3];

	colar[RED] = 0;
	colar[GREEN] = 0;
	colar[BLUE] = 0;
	while (ft_isspace(*read_line) == TRUE)
		read_line++;
	read_line = split_colar(read_line, &colar[RED]);
	read_line = split_colar(read_line, &colar[GREEN]);
	read_line = split_colar(read_line, &colar[BLUE]);
	if (colar[RED] < 0 || colar[GREEN] < 0 || colar[BLUE] < 0)
		err_exit("colar is under 0");
	if (colar[RED] > 255 || colar[GREEN] > 255 || colar[BLUE] > 255)
		err_exit("colar is over 255");
	return (colar[RED] << 16 | colar[GREEN] << 8 | colar[BLUE]);
}

void	check_component(int fd, t_map *map)
{
	char	*read_line;
	int		map_count;

	map_count = 0;
	read_line = get_next_line(fd);
	while (read_line != NULL && map_count != 6)
	{
		if (ft_strncmp("NO ", read_line, 3) == 0 && ++map_count)
			map->no_path = check_path(read_line + 2);
		else if (ft_strncmp("SO ", read_line, 3) == 0 && ++map_count)
			map->so_path = check_path(read_line + 2);
		else if (ft_strncmp("WE ", read_line, 3) == 0 && ++map_count)
			map->we_path = check_path(read_line + 2);
		else if (ft_strncmp("EA ", read_line, 3) == 0 && ++map_count)
			map->ea_path = check_path(read_line + 2);
		else if (ft_strncmp("F ", read_line, 2) == 0 && ++map_count)
			map->floor = check_colar(read_line + 1);
		else if (ft_strncmp("C ", read_line, 2) == 0 && ++map_count)
			map->ceiling = check_colar(read_line + 1);
		free(read_line);
		if (map_count != 6)
			read_line = get_next_line(fd);
	}
	if (map_count != 6)
		err_exit("Insufficient map contents");
}
//////////////////////////////////////////////////////////
void	check_and_add_map(int fd, t_map *map)
{
	char	*map_line;

	map_line = get_next_line(fd);
	free(map_line);
	map_line = get_next_line(fd);
	(void)map;
	while (map_line != NULL)
	{
		printf("map = %s", map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
}
/////////////////////////////////////////////////////
t_map	*check_and_return_map(char *map_file)
{
	t_map		*map;
	const int	fd = open(map_file, O_RDONLY);

	map = malloc(sizeof(t_map));
	if (errno == 2)
		err_exit("No such file or directory");
	else if (errno == 13)
		err_exit("Permission denied");
	else if (fd < 0)
		err_exit("File open error");
	check_component(fd, map);
	check_and_add_map(fd, map);
	close(fd);
	return (NULL);
}
