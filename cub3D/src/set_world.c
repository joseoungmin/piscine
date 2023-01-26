/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 23:12:36 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

void	set_world(t_map *map)
{
	world_malloc(map);
	render_map(map);
	map->player->img = mlx_new_image(map->world->mlx, (int)(MINI_SCALE * map->width * TILE_SIZE), (int)(MINI_SCALE * map->height * TILE_SIZE));
	set_player(map);
	draw_player(map);
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, (int)(map->width * TILE_SIZE * (1 -  MINI_SCALE)), (int)(map->height * TILE_SIZE * (1 - MINI_SCALE)));
	//mlx_key_hook();
}
