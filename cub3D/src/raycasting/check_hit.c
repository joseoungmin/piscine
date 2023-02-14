/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:15:40 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:37:10 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "check_hit.h"

void	cal_texture_type(t_world *world, t_raycast *rc, t_texture *tex)
{
	if (rc->is_side == 0)
	{
		tex->wall_x = world->player.pos.y + rc->d * rc->ray.y;
		tex->type = NO;
		if (rc->step.x > 0)
			tex->type = SO;
	}
	else
	{
		tex->wall_x = world->player.pos.x + rc->d * rc->ray.x;
		tex->type = WE;
		if (rc->step.y > 0)
			tex->type = EA;
	}
}

void	check_hit(t_world *world, t_player *p, t_raycast *rc, t_texture *tex)
{
	while (1)
	{
		if (rc->side.x < rc->side.y)
		{
			rc->side.x += rc->delta.x;
			rc->block.x += rc->step.x;
			rc->is_side = 0;
		}
		else
		{
			rc->side.y += rc->delta.y;
			rc->block.y += rc->step.y;
			rc->is_side = 1;
		}
		if (world->map[rc->block.y][rc->block.x] == '1')
			break ;
	}
	if (rc->is_side == 0)
		rc->d = (rc->block.x - p->pos.x + (1 - rc->step.x) / 2.0) / rc->ray.x;
	else
		rc->d = (rc->block.y - p->pos.y + (1 - rc->step.y) / 2.0) / rc->ray.y;
	cal_texture_type(world, rc, tex);
}
