/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/28 16:20:31 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

void	draw_ray(t_map *map)
{	
	draw_player(map);
}

int	ft_loop(t_map *map)
{
	render_map(map);
	draw_ray(map);
	move_check(map);// will make key_check.c
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, \
			(int)(map->width * TILE_SIZE * (1 - MINI_SCALE)), \
			(int)(map->height * TILE_SIZE * (1 - MINI_SCALE)));
	return (0);
}

void	set_world(t_map *map)
{
	init_world(map);
	render_map(map);
	map->player->img = mlx_new_image(map->world->mlx, \
			(int)(MINI_SCALE * map->width * TILE_SIZE), \
			(int)(MINI_SCALE * map->height * TILE_SIZE));
	set_player(map);
	draw_player(map);
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, \
			(int)(map->width * TILE_SIZE * (1 - MINI_SCALE)), \
			(int)(map->height * TILE_SIZE * (1 - MINI_SCALE)));
	//mlx_key_hook();
}
