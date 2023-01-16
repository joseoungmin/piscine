/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_count_alloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:45:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/15 14:47:43 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_count_alloc.h"

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
