/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_count_alloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:45:31 by seojo             #+#    #+#             */
/*   Updated: 2023/02/12 04:11:45 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_count_alloc.h"

void	count_map(t_world *world, int fd)
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
		safe_free(count_line);
		count_line = get_next_line(fd);
	}
	world->map_h = ++y_cnt;
	world->map_w = x_max;
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
		safe_free(count_line);
		idx++;
	}
	return (fd);
}

void	map_alloc(t_world *world)
{
	int	y;
	int	x;

	world->map = malloc(sizeof(char *) * (world->map_h + 1));
	if (world->map == NULL)
		err_exit("map_alloc : malloc failed");
	y = 0;
	while (y < world->map_h)
	{
		world->map[y] = malloc(sizeof(char) * world->map_w + 1);
		if (world->map[y] == NULL)
			err_exit("map_alloc : malloc failed");
		y++;
	}
	y = 0;
	while (y < world->map_h)
	{
		x = 0;
		while (x < world->map_w)
			world->map[y][x++] = ' ';
		y++;
	}
	world->map[y] = NULL;
}
