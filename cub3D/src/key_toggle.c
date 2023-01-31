/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:55 by seojo             #+#    #+#             */
/*   Updated: 2023/01/31 16:42:16 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_toggle.h"

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

int	key_release(int keycode, t_map *map)
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

void	rot_check(t_map *map)
{
	const double	old_dir_x = map->player->dir_x;
	const double	old_plane_x = map->player->plane_x;
	double			theta;

	if (map->key->left && map->key->right)
		return ;
	else if (map->key->left == 1)
		theta = -map->player->rot_speed;
	else if (map->key->right == 1)
		theta = map->player->rot_speed;
	else
		return ;
	map->player->dir_x = old_dir_x * cos(theta) - \
						map->player->dir_y * sin(theta);
	map->player->dir_y = old_dir_x * sin(theta) + \
						map->player->dir_y * cos(theta);
	map->player->plane_x = map->player->plane_x * \
						cos(theta) - map->player->plane_y * sin(theta);
	map->player->plane_y = old_plane_x * \
						sin(theta) + map->player->plane_y * cos(theta);
}

void	move_check(t_map *map)
{
	if (map->key->w && map->key->s)
		;
	else if (map->key->w)
		move_forward(map);
	else if (map->key->s)
		move_backward(map);
	if (map->key->a && map->key->d)
		;
	else if (map->key->a)
		move_left(map);
	else if (map->key->d)
		move_right(map);
	rot_check(map);
}
