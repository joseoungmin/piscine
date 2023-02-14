/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:04:30 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:29:30 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "init_rc.h"

void	init_rc(t_world *world, t_raycast *rc, int x)
{
	t_player	*p;

	p = &world->player;
	rc->cam_y = 2 * x / (double)world->screen_w - 1;
	rc->ray.x = p->dir.x + p->plane.x * rc->cam_y;
	rc->ray.y = p->dir.y + p->plane.y * rc->cam_y;
	rc->block.x = (int)p->pos.x;
	rc->block.y = (int)p->pos.y;
	rc->delta.x = fabs(1 / rc->ray.x);
	rc->delta.y = fabs(1 / rc->ray.y);
}
