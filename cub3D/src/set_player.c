/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:29:14 by seojo             #+#    #+#             */
/*   Updated: 2023/01/29 20:45:20 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_player.h"

void	set_player_dir_sub(t_map *map)
{
	if (map->direction == 'W')
	{
		map->player->dir_x = -1;
		map->player->dir_y = 0;
		map->player->plane_x = 0;
		map->player->plane_y = -0.66;
	}
	else if (map->direction == 'E')
	{
		map->player->dir_x = 1;
		map->player->dir_y = 0;
		map->player->plane_x = 0;
		map->player->plane_y = 0.66;
	}
}

void	set_player_dir(t_map *map)
{
	if (map->direction == 'N')
	{
		map->player->dir_x = 0;
		map->player->dir_y = -1;
		map->player->plane_x = 0.66;
		map->player->plane_y = 0;
	}
	else if (map->direction == 'S')
	{
		map->player->dir_x = 0;
		map->player->dir_y = 1;
		map->player->plane_x = -0.66;
		map->player->plane_y = 0;
	}
	set_player_dir_sub(map);
}

int	draw_player(t_map *map)
{
	int	row;
	int	col;
	
	row = -map->player->thickness / 2;
	while (row <= (map->player->thickness / 2))
	{
		col = -map->player->thickness / 2;
		while (col <= (map->player->thickness / 2))
		{
			map->world->data[(int)(MINI_SCALE * (map->width * TILE_SIZE) * \
			((int)map->player->y + row) + \
			((int)map->player->x + col))] = 0x0000FF;
			col++;
		}
		row++;
	}
	return (0);
}

void	set_player(t_map *map)
{
	set_player_dir(map);
}
