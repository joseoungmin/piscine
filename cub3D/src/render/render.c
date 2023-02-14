/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:57:29 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 16:07:12 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	next_frame(t_world *world)
{
	action(world);
	set_world(world);
	world_on_screen(world, world->tmlx);
	return (0);
}

void	render(t_world *world)
{
	t_mlx	*tmlx;

	tmlx = world->tmlx;
	init_screen_buf(world);
	set_world(world);
	world_on_screen(world, world->tmlx);
	mlx_loop_hook(tmlx->mlx, &next_frame, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_PRESS, 0, &key_press, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_RELEASE, 0, &key_release, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_DESTROY_NOTIFY, 0, &event_red_cross, 0);
	mlx_loop(tmlx->mlx);
}
