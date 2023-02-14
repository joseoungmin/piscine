/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:46 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:40:43 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

void	map_obj_check(t_world *world, char c)
{
	int			idx;
	const char	object_arr[7] = " 01NSEW";

	idx = 0;
	while (idx < 7 && c != object_arr[idx])
		idx++;
	if (idx == 7)
		err_exit("Invalid map object");
	if (world->player.cardinal == 0 && (c == 'N' || c == 'S' \
										|| c == 'E' || c == 'W'))
		world->player.cardinal = c;
	else if (world->player.cardinal != 0 && \
			(c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		err_exit("Too many players");
}

void	read_map(t_world *world, int fd, int y, int x)
{
	char	c;

	y = -1;
	while (++y < world->map_h)
	{
		x = -1;
		while (++x < world->map_w)
		{
			if (read(fd, &world->map[y][x], 1) < 0)
				return ;
			if (c == '\n' && c == world->map[y][x])
				err_exit("Invalid map object : emptyline");
			c = world->map[y][x];
			if (world->map[y][x] == '\n')
			{
				world->map[y][x] = ' ';
				break ;
			}
			else
				map_obj_check(world, world->map[y][x]);
		}
	}
	if (world->player.cardinal == 0)
		err_exit("Player is missing");
}

void	check_and_add_map(t_world *world, int fd, \
char *filename, int file_height)
{
	count_map(world, fd);
	map_alloc(world);
	close(fd);
	fd = reopen_fd(filename, file_height);
	read_map(world, fd, 0, 0);
	close(fd);
}

void	check_map(t_world *world, char *map_file)
{
	int			file_height;
	const int	fd = ft_open(map_file);

	file_height = check_component(world, fd);
	check_and_add_map(world, fd, map_file, file_height);
	check_eight_directions(world, world->map, world->map_h, world->map_w);
}
