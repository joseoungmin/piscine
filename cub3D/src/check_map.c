/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:46 by seojo             #+#    #+#             */
/*   Updated: 2023/01/15 16:28:01 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

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
	check_eight_directions(map->map, map->height, map->width);
	return (map);
}
