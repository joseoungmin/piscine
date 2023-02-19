/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 13:44:15 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	return (world);
}

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

int	main(int ac, char **av)
{
	t_world	*world;

	check_argument(ac, av);
	world = init_world();
	init_player(&world->player);
	check_map(world, av[1]);
	init_render(world);
	render(world);
	clear_world(world);
	return (0);
}
