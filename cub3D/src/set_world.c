/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 12:15:31 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

#define WINDOW_W	920
#define WINDOW_H	640

/*
int	move_check(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		move_up(game);
	else if (key == KEY_A)
		move_left(game);
	else if (key == KEY_S)
		move_down(game);
	else if (key == KEY_D)
		move_right(game);
	else if (key == KEY_LEFT)
		//key_left_func;
	else if (key == KEY_RIGHT)
		//key_right_func;
	//map_draw(game); 맵 렌더링 어떻게 할지 생각하기 
	return (0);
}
*/
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

	// mlx hook and open window
//	mlx_hook(world->win, X_KEY_PRESS, 0, move_check, //structere);
//	mlx_hook(world->win, X_KEY_EXIT, 0, endgame, //structere);
//	mlx_loop(world->mlx);
}

void	set_world(t_map *map)
{
//	t_world	*world;
	set_player(map);
//	set_image(map);
	//mlx_key_hook();
}
