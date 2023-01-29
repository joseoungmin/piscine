/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:41:37 by seojo             #+#    #+#             */
/*   Updated: 2023/01/29 20:45:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

#include <math.h>
#define _USE_MATH_DEFINES
#define PI M_PI

static t_key	*init_key(void)
{
	t_key *key;

	key = malloc(sizeof(t_key));
	if (key == NULL)
		err_exit("init_key : malloc failed");
	key->a = 0;
	key->d = 0;
	key->w = 0;
	key->s = 0;
	key->left = 0;
	key->right = 0;
	return (key);
}

static t_player    *init_player(void)
{
	t_player    *player;

	player = malloc(sizeof(t_player));
	if (!player)
		err_exit("init_player : malloc failed");
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->move_speed = 1;
	player->rot_speed = 4 * (PI / 180);
	player->thickness = PLAYER_THICKNESS;
	return (player);
}

void	init_world(t_map *map)
{
	map->world = malloc(sizeof(t_world));
	if (map->world == NULL)
		err_exit("init_world : malloc failed");
	map->world->mlx = mlx_init();
	map->world->win = mlx_new_window(map->world->mlx, map->width * \
			TILE_SIZE, map->height * TILE_SIZE, "cub3D");
	map->world->img = mlx_new_image(map->world->mlx, \
			(int)(MINI_SCALE * map->width * TILE_SIZE), \
			(int)(MINI_SCALE * map->height * TILE_SIZE));
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		err_exit("init_map : malloc failed");
	map->map = NULL;
	map->floor = 0;
	map->width = 0;
	map->direction = 0;
	map->player = init_player();
	map->key = init_key();
	return (map);
}
