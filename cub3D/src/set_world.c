/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 13:26:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

int	ft_loop(t_map *map)
{
	render_map(map);
	draw_player(map);
	draw_ray(map);
	move_check(map);
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, 0, 0);
	return (0);
}

void	set_world(t_map *map)
{
	init_world(map);
	render_map(map);
	map->player->img = mlx_new_image(map->world->mlx, \
		(int)(map->width * MINI_SCALE), \
		(int)(map->height * MINI_SCALE));
	set_player(map);
	draw_player(map);
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, 0, 0);
}
