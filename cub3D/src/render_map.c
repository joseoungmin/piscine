/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:57:29 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 18:48:03 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

void	fill_rectangle(t_map *map, int x, int y, int color)
{
	int		i;
	int		j;

	j = 0;
	while (j < (int)(MINI_SCALE * TILE_SIZE))
	{
		i = 0;
		while (i < (int)(MINI_SCALE * TILE_SIZE))
		{
			map->world->data[(int)(MINI_SCALE * map->width * TILE_SIZE) * \
			(y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

void	render_map(t_map *map)
{
	int		col;
	int		row;

	map->world->data = (int *)mlx_get_data_addr(map->world->img, \
			&map->world->bpp, &map->world->line_len, &map->world->endian);
	row = 0;
	while (row < map->height - 1)
	{
		col = 0;
		while (col < map->width - 1)
		{
			if (map->map[row][col] == '1')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0x282828);
			else if (map->map[row][col] == '0')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0xFFFFFF);
            else if (map->map[row][col] == ' ')
                fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0x000000);
            else
                fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0xFFFFFF);
			col++;
		}
		row++;
	}
}

void	world_malloc(t_map *map)
{
	map->world = malloc(sizeof(t_world));
	if (map->world == NULL)
		err_exit("set_image : malloc fail");
	map->world->mlx = mlx_init();
	map->world->win = mlx_new_window(map->world->mlx, map->width * \
			TILE_SIZE, map->height * TILE_SIZE, "cub3D");
	map->world->img = mlx_new_image(map->world->mlx, \
			(int)(MINI_SCALE * map->width * TILE_SIZE), \
			(int)(MINI_SCALE * map->height * TILE_SIZE));
}
