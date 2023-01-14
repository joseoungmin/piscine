/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:46 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 21:53:24 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

#include <stdio.h>

8way parse think

void	map_obj_check(char c, t_map *map)
{
	int			idx;
	const char	object_arr[7] = " 01NSEW";

	idx = 0;
	while (idx < 7 && c != object_arr[idx])
		idx++;
	if (idx == 7)
		err_exit("Invalid map object");
	if (map->direction == 0 && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		map->direction = c;
	else if (map->direction != 0 && \
			(c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		err_exit("Too many players");
}

void	count_map(int fd, t_map *map)
{
	int		y_cnt;
	int		x_cnt;
	int		x_max;
	char	*count_line;

	y_cnt = 0;
	x_max = 0;
	count_line = get_next_line(fd);
	while (count_line != NULL)
	{
		x_cnt = 0;
		while (count_line[x_cnt] != '\0')
			x_cnt++;
		if (x_cnt > x_max)
			x_max = x_cnt;
		y_cnt++;
		free(count_line);
		count_line = get_next_line(fd);
	}
	map->height = ++y_cnt;
	map->width = x_max;
}

int	reopen_fd(char *filename, int file_height)
{
	const int	fd = ft_open(filename);
	int			idx;
	char		*count_line;

	idx = 0;
	while (idx < file_height)
	{
		count_line = get_next_line(fd);
		free(count_line);
		idx++;
	}
	return (fd);
}

void	map_alloc(t_map *map)
{
	int	y;
	int	x;

	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (map->map == NULL)
		err_exit("map_alloc : malloc fail");
	y = 0;
	while (y < map->height)
	{
		map->map[y] = malloc(sizeof(char) * map->width + 1);
		if (map->map[y] == NULL)
			err_exit("map_alloc : malloc fail");
		y++;
	}
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
			map->map[y][x++] = ' ';
		y++;
	}
	map->map[y] = NULL;
}

void	read_map(t_map *map, int fd, int y, int x)
{
	char	c;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (read(fd, &map->map[y][x], 1) < 0)
				return ;
			if (c == '\n' && c == map->map[y][x])
				err_exit("Invalid map object : emptyline");
			c = map->map[y][x];
			if (map->map[y][x] == '\n')
			{
				map->map[y][x] = ' ';
				break ;
			}
			else
				map_obj_check(map->map[y][x], map);
		}
	}
	if (map->direction == 0)
		err_exit("Player is missing");
}

void	check_and_add_map(int fd, t_map *map, char *filename, int file_height)
{
	count_map(fd, map);
	map_alloc(map);
	close(fd);
	fd = reopen_fd(filename, file_height); 
	map->direction = 0;
	read_map(map, fd, 0, 0);
	close(fd);
}

t_map	*check_and_return_map(char *map_file)
{
	int			file_height;
	t_map		*map;
	const int	fd = ft_open(map_file);

	map = malloc(sizeof(t_map));
	if (map == NULL)
		err_exit("check_and_return_map : malloc fail");
	file_height = check_component(fd, map);
	check_and_add_map(fd, map, map_file, file_height);

/// map print ///
	printf("\n========== PRINT OBJ ==========\n\n");
	printf("NO = [%s]\n", map->no_path);
	printf("SO = [%s]\n", map->so_path);
	printf("WE = [%s]\n", map->we_path);
	printf("EA = [%s]\n", map->ea_path);
	printf("F = [%x]\n", map->floor);
	printf("C = [%x]\n", map->ceiling);
	printf("player direction = %c\n", map->direction);
	printf("\n========== PRINT MAP ==========\n\n");
	for (int y=0; y < map->height; y++)
	{
		for(int x=0; x < map->width; x++)
			printf("%c", map->map[y][x]);
		printf("\n");
	}
	printf("\n ========== END MAP ========== \n\n");
/// map pirnt ///

//	system("Leaks cub3D");
	return (map);
}
