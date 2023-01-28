/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:55 by seojo             #+#    #+#             */
/*   Updated: 2023/01/28 15:57:53 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_toggle.h"

void    check_wall(t_map *map, int old_x, int old_y)
{
	int x;
	int y;

	x = (int)map->player->x / TILE_SIZE;
	y = (int)map->player->y / TILE_SIZE;
	if (map->map[y][x] == '1')
	{
		map->player->x = old_x;
		map->player->y = old_y;
	}
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
	int old_x;
	int old_y;

	old_x = (int)map->player->x;
	old_y = (int)map->player->y;
	if (map->key->w)
		map->player->y -= map->player->move_speed;
	if (map->key->s)
		map->player->y += map->player->move_speed;
	if (map->key->a)
		map->player->x -= map->player->move_speed;
	if (map->key->d)
		map->player->x += map->player->move_speed;
	// if (map->key->left)
	// 	map->player->rot_speed = -0.05;
	// if (map->key->right)
	// 	map->player->rot_speed = 0.05;
	check_wall(map, old_x, old_y);
}
