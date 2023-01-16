/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eight_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:26:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/15 16:31:18 by seojo            ###   ########.fr       */
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

void	check_eight_directions(char **map, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == '0')
			{
				if (x < 1 || y < 1 || x >= width || y >= height)
					err_exit("Invaild map");
				eight_direction_validation(map, y, x);
			}
			x++;
		}
		y++;
	}
}
