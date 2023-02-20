/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:56:15 by seojo             #+#    #+#             */
/*   Updated: 2023/02/20 15:57:06 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world.h"

void	init_player(t_player *p)
{
	p->dir.x = 0.0;
	p->dir.y = -1.0;
	p->plane.x = 0.5;
	p->plane.y = 0.0;
	p->move_speed = 0.04;
	p->rot_speed = 0.05;
	p->cardinal = 0;
}

t_world	*init_world(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	if (!world)
		err_exit("world malloc error");
	world->screen_w = WIN_W;
	world->screen_h = WIN_H;
	world->tex_path[NO] = NULL;
	world->tex_path[SO] = NULL;
	world->tex_path[WE] = NULL;
	world->tex_path[EA] = NULL;
	world->floor = -1;
	world->ceiling = -1;
	world->keycode = 0;
	world->map = NULL;
	init_player(&world->player);
	return (world);
}
