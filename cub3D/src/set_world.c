/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/16 15:59:25 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

#define WINDOW_W	1440
#define WINDOW_H	920

void	set_image(t_map *map)
{
	void	*mlx;
	void	*win;
	(void)map;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_W, WINDOW_H, "cub3D");
	mlx_loop(mlx);
}

void	set_world(t_map *map)
{
//	t_world	*world;

	set_image(map);
}
