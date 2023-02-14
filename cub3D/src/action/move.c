/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:13 by seojo             #+#    #+#             */
/*   Updated: 2023/02/12 19:24:27 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

static	int	is_space(char spot)
{
	if (spot == WALL)
		return (0);
	return (1);
}

void	move_right(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x - p->dir.y * p->move_speed)]))
		p->pos.x += -p->dir.y * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y + p->dir.x * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y += p->dir.x * p->move_speed;
}

void	move_left(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x + p->dir.y * p->move_speed)]))
		p->pos.x += p->dir.y * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y - p->dir.x * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y += -p->dir.x * p->move_speed;
}

void	move_backward(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x - p->dir.x * p->move_speed)]))
		p->pos.x -= p->dir.x * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y - p->dir.y * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y -= p->dir.y * p->move_speed;
}

void	move_foreward(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x + p->dir.x * p->move_speed)]))
		p->pos.x += p->dir.x * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y + p->dir.y * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y += p->dir.y * p->move_speed;
}
