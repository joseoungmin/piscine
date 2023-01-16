/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/16 17:29:17 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

#define WINDOW_W	1440
#define WINDOW_H	920

void	set_image(t_map *map)
{
	t_world	*world;

	(void)map;

	world = malloc(sizeof(t_world));
	if (world == NULL)
		err_exit("set_image : malloc fail");
	world->mlx = mlx_init();
	world->win = mlx_new_window(world->mlx, WINDOW_W, WINDOW_H, "cub3D");
	world->img = mlx_new_image(world->mlx, WINDOW_W, WINDOW_H);
	world->data = (int *)mlx_get_data_addr(world->img, &world->bpp, \
					&world->line_len, &world->endian);
	mlx_loop(world->mlx);
}

void	set_world(t_map *map)
{
//	t_world	*world;

	set_image(map);
}
