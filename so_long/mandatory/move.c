/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:47:43 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 14:29:44 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_down(t_game *game)
{
	if (game->map_arr[game->gps.y + 1][game->gps.x] == '1')
		return ;
	else if (game->map_arr[game->gps.y + 1][game->gps.x] == 'C')
		game->coin_cnt--;
	else if (game->map_arr[game->gps.y + 1][game->gps.x] == 'E' && \
			game->coin_cnt > 0)
		return ;
	else if (game->map_arr[game->gps.y + 1][game->gps.x] == 'E' && \
			game->coin_cnt == 0)
		bye(game);
	game->map_arr[game->gps.y][game->gps.x] = '0';
	game->gps.y++;
	game->map_arr[game->gps.y][game->gps.x] = 'P';
	printf("move_count : %d\n", ++game->move_cnt);
}

void	move_up(t_game *game)
{
	if (game->map_arr[game->gps.y - 1][game->gps.x] == '1')
		return ;
	else if (game->map_arr[game->gps.y - 1][game->gps.x] == 'C')
		game->coin_cnt--;
	else if (game->map_arr[game->gps.y - 1][game->gps.x] == 'E' && \
			game->coin_cnt > 0)
		return ;
	else if (game->map_arr[game->gps.y - 1][game->gps.x] == 'E' && \
			game->coin_cnt == 0)
		bye(game);
	game->map_arr[game->gps.y][game->gps.x] = '0';
	game->gps.y--;
	game->map_arr[game->gps.y][game->gps.x] = 'P';
	printf("move_count : %d\n", ++game->move_cnt);
}

void	move_left(t_game *game)
{
	if (game->map_arr[game->gps.y][game->gps.x - 1] == '1')
		return ;
	else if (game->map_arr[game->gps.y][game->gps.x - 1] == 'C')
		game->coin_cnt--;
	else if (game->map_arr[game->gps.y][game->gps.x - 1] == 'E' && \
			game->coin_cnt > 0)
		return ;
	else if (game->map_arr[game->gps.y][game->gps.x - 1] == 'E' && \
			game->coin_cnt == 0)
		bye(game);
	game->map_arr[game->gps.y][game->gps.x] = '0';
	game->gps.x--;
	game->map_arr[game->gps.y][game->gps.x] = 'P';
	printf("move_count : %d\n", ++game->move_cnt);
}

void	move_right(t_game *game)
{
	if (game->map_arr[game->gps.y][game->gps.x + 1] == '1')
		return ;
	else if (game->map_arr[game->gps.y][game->gps.x + 1] == 'C')
		game->coin_cnt--;
	else if (game->map_arr[game->gps.y][game->gps.x + 1] == 'E' && \
			game->coin_cnt > 0)
		return ;
	else if (game->map_arr[game->gps.y][game->gps.x + 1] == 'E' && \
			game->coin_cnt == 0)
		bye(game);
	game->map_arr[game->gps.y][game->gps.x] = '0';
	game->gps.x++;
	game->map_arr[game->gps.y][game->gps.x] = 'P';
	printf("move_count : %d\n", ++game->move_cnt);
}

int	move_check(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP)
		move_up(game);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	map_draw(game);
	return (0);
}
