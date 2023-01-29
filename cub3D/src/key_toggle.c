/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:55 by seojo             #+#    #+#             */
/*   Updated: 2023/01/29 21:08:53 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_toggle.h"

#include <math.h>

int    is_wall(t_map *map)
{
	int x;
	int y;

	x = (int)map->player->x / TILE_SIZE;
	y = (int)map->player->y / TILE_SIZE;
	if (map->map[y][x] == '1')
		return (1);
	return (0);
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_A)
		map->key->a = 1;
	else if (keycode == KEY_D)
		map->key->d = 1;
	else if (keycode == KEY_W)
		map->key->w = 1;
	else if (keycode == KEY_S)
		map->key->s = 1;
	else if (keycode == KEY_LEFT)
		map->key->left = 1;
	else if (keycode == KEY_RIGHT)
		map->key->right = 1;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int key_release(int keycode, t_map *map)
{
	if (keycode == KEY_A)
		map->key->a = 0;
	else if (keycode == KEY_D)
		map->key->d = 0;
	else if (keycode == KEY_W)
		map->key->w = 0;
	else if (keycode == KEY_S)
		map->key->s = 0;
	else if (keycode == KEY_LEFT)
		map->key->left = 0;
	else if (keycode == KEY_RIGHT)
		map->key->right = 0;
	return (0);
}

void    move_check(t_map *map)
{
	const double	old_x = map->player->x;
	const double	old_y = map->player->y;

	if (map->key->w && map->key->s)
		;
	else if (map->key->w)
	{
		map->player->x += map->player->dir_x * map->player->move_speed;
		map->player->y += map->player->dir_y * map->player->move_speed;
	}
	else if (map->key->s)
	{
		map->player->x -= map->player->dir_x * map->player->move_speed;
		map->player->y -= map->player->dir_y * map->player->move_speed;
	}

	if (map->key->a && map->key->d)
		;
	else if (map->key->a)
	{
		map->player->x += map->player->dir_y * map->player->move_speed;
		map->player->y -= map->player->dir_x * map->player->move_speed;

	}
	else if (map->key->d)
	{
		map->player->x -= map->player->dir_y * map->player->move_speed;
		map->player->y += map->player->dir_x * map->player->move_speed;
	}

	const double	old_dir_x = map->player->dir_x;
	const double	old_plane_x = map->player->plane_x;
	double			theta = 0.0;

	if (map->key->left && map->key->right)
		;
	else if (map->key->left == 1)
		theta = -map->player->rot_speed;
	else if (map->key->right == 1)
		theta = map->player->rot_speed;
	else
		theta = 0;//  함수로 빼면 리턴 ;
	map->player->dir_x = old_dir_x * cos(theta) - map->player->dir_y * sin(theta);
	map->player->dir_y = old_dir_x * sin(theta) + map->player->dir_y * cos(theta);
	map->player->plane_x = map->player->plane_x * cos(theta) - map->player->plane_y * sin(theta);
	map->player->plane_y = old_plane_x * sin(theta) + map->player->plane_y * cos(theta);
	if (is_wall(map) == 1)
	{
		map->player->x = old_x;
		map->player->y = old_y;
	}
}
