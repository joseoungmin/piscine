/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:46 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 15:28:17 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

#include <stdio.h>

int	ft_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (errno == 2)
		err_exit("No such file or directory");
	else if (errno == 13)
		err_exit("Permission denied");
	else if (fd < 0)
		err_exit("File open error");
	return (fd);
}

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

	while (ft_isspace(*read_line) == TRUE)
		read_line++;
	if (*read_line == '\n' || *read_line == '\0')
		err_exit("Invalid path object");
	filename = split_filename(read_line);
	fd = ft_open(read_line);
	close(fd);
	return (filename);
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
	while (*read_line && ft_isdigit(*read_line) == 0 && \
			*read_line != '-' && *read_line != '+')
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
	else if (colar[RED] > 255 || colar[GREEN] > 255 || colar[BLUE] > 255)
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

char	map_object_check(char *map_line)
{
	int			idx;
	char		c;
	const char	object_arr[7] = " 01NSEW";

	c = 0;
	while (*map_line == ' ')
		map_line++;
	if (*map_line == '\n')
		err_exit("Invalid map object");
	while (map_line && *map_line)
	{
		idx = 0;
		while (*map_line && *map_line != '\n' && idx < 7 && \
				*map_line != object_arr[idx])
			idx++;
		if (idx == 7)
			err_exit("Invalid map object");
		if (*map_line == 'N' || *map_line == 'S' || \
				*map_line == 'E' || *map_line == 'W')
				c = *map_line;
		map_line++;
	}
	return (c);
}

void	pass_new_line(int fd)
{
	char	*new_line;

	new_line = get_next_line(fd);
	while (*new_line == ' ')
		new_line++;
	if (*new_line == '\n')
		free(new_line);
	else
		err_exit("Invalid map object");
}

int	close_fd_and_count_map(int fd)
{
	int		y_cnt;
	char	*count_line;

	pass_new_line(fd);
	y_cnt = 0;
	count_line = get_next_line(fd);
	while (count_line != NULL)
	{
		y_cnt++;
		free(count_line);
		count_line = get_next_line(fd);
	}
	close(fd);
	return (++y_cnt);
}

int	reopen_fd(char *filename)
{
	const int	fd = ft_open(filename);
	int			idx;
	char		*count_line;

	idx = 0;
	while (idx < 8)
	{
		count_line = get_next_line(fd);
		free(count_line);
		idx++;
	}
	return (fd);
}

void	check_and_add_map(int fd, t_map *map, char *filename)
{
	int		i;
	int		y;
	char	dir_tmp;

	y = close_fd_and_count_map(fd);
	fd = reopen_fd(filename); 
	map->map = malloc(sizeof(char *) * y);
	if (map->map == NULL)
		err_exit("check_and_add_map : malloc fail");
	i = 0;
	map->direction = 0;
	map->map[i] = get_next_line(fd);
	while (map->map[i] != NULL)
	{
		dir_tmp = map_object_check(map->map[i++]);
		if (dir_tmp != 0 && map->direction == 0)
			map->direction = dir_tmp;
		else if (dir_tmp != 0 && map->direction != 0)
			err_exit("Too many players");
		map->map[i] = get_next_line(fd);
	}
	close(fd);
}
/////////////////////////////////////////////////////
t_map	*check_and_return_map(char *map_file)
{
	t_map		*map;
	const int	fd = ft_open(map_file);

	map = malloc(sizeof(t_map));
	if (map == NULL)
		err_exit("check_and_return_map : malloc fail");
	check_component(fd, map);
	check_and_add_map(fd, map, map_file);

/// map print ///
	printf("NO = [%s]\n", map->no_path);
	printf("SO = [%s]\n", map->so_path);
	printf("WE = [%s]\n", map->we_path);
	printf("EA = [%s]\n", map->ea_path);
	printf("F = [%x]\n", map->floor);
	printf("C = [%x]\n", map->ceiling);
	for (int i=0; map->map[i]; i++)
		printf("%s", map->map[i]);
	printf("player dir = %c\n", map->direction);
/// map pirnt ///

//	system("Leaks cub3D");
	return (NULL);
}
