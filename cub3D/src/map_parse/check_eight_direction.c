/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eight_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:26:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/23 23:55:53 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "check_eight_direction.h"

static void	eight_direction_validation(char **map, int y, int x)
{
	if (map[y - 1][x] == ' ' || map[y - 1][x + 1] == ' ' || \
		map[y][x + 1] == ' ' || map[y + 1][x + 1] == ' ' || \
		map[y + 1][x] == ' ' || map[y + 1][x - 1] == ' ' || \
		map[y][x - 1] == ' ' || map[y - 1][x - 1] == ' ')
		err_exit("Invalid map");
}

void	check_eight_directions(t_map *tmap, char **map, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E' || \
				map[y][x] == 'S' || map[y][x] == 'W')
			{
				if (x < 1 || y < 1 || x >= width - 1 || y >= height - 1)
					err_exit("Invaild map");
				eight_direction_validation(map, y, x);
				if (map[y][x] != '0')
				{
					tmap->player->x = x + 0.5;
					tmap->player->y = y + 0.5;
				}
			}
			x++;
		}
		y++;
	}
}
