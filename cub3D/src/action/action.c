/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:58:08 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 01:22:16 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

static void	action_internal(const t_keycode key, t_world *world)
{
	int					i;
	const t_keycode		key_table[] = {KEY_W, KEY_A, KEY_S, KEY_D, KEY_ESC};
	const t_key_action	func_table[] = {
		move_foreward, move_left,
		move_backward, move_right,
		event_close};

	if (key == KEY_NONE)
		return ;
	i = 0;
	while (i < 5)
	{
		if (key_table[i] == key)
		{
			func_table[i](world);
			break ;
		}
		i++;
	}
}

static void	move_sight(int keycode, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	theta;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	if (keycode == KEY_ARROW_R)
		theta = p->rot_speed;
	else if (keycode == KEY_ARROW_L)
		theta = -p->rot_speed;
	else
		return ;
	p->dir.x = p->dir.x * cos(theta) - p->dir.y * sin(theta);
	p->dir.y = old_dir_x * sin(theta) + p->dir.y * cos(theta);
	p->plane.x = p->plane.x * cos(theta) - p->plane.y * sin(theta);
	p->plane.y = old_plane_x * sin(theta) + p->plane.y * cos(theta);
}

t_keycode	which_is_functinal(t_keycode key1, t_keycode key2, int keycode)
{
	if ((keycode & 1 << find_key(key1)) && (keycode & 1 << find_key(key2)) == 0)
		return (key1);
	if ((keycode & 1 << find_key(key2)) && (keycode & 1 << find_key(key1)) == 0)
		return (key2);
	return (KEY_NONE);
}

static void	action_by_each_keys(t_world *world)
{
	if (world->keycode & 1 << find_key(KEY_ESC))
		action_internal(KEY_ESC, world);
	move_sight(which_is_functinal(KEY_ARROW_R, KEY_ARROW_L, world->keycode),
		&world->player);
	action_internal(which_is_functinal(KEY_W, KEY_S, world->keycode),
		world);
	action_internal(which_is_functinal(KEY_A, KEY_D, world->keycode),
		world);
}

void	action(t_world *world)
{
	if (world->keycode != 0)
		action_by_each_keys(world);
}
