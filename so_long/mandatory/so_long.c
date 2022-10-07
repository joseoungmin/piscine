/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:25:30 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 13:05:31 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_down(t_game *game)
{
	if (game->map_arr[game->gps.y + 1][game->gps.x] == '1')
		return ;
	game->map_arr[game->gps.y][game->gps.x] = '0';
	game->gps.y++;
	game->map_arr[game->gps.y][game->gps.x] = 'P';
}

//if (pl_location == 1)
//	pl_location = before;

int	gps_check(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP)
		game->gps.y++;
	else if (key == KEY_A || key == KEY_LEFT)
		game->gps.x--;
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_D || key == KEY_RIGHT)
		game->gps.x++;
	printf("x: %d, y: %d\n", game->gps.x, game->gps.y);
	return (0);
}	

void	init_game(t_game *game)
{
	game->map_hei = 0;
	game->map_wid = 0;
	game->map_cols = 0;
	game->map_rows = 0;
	game->map_arr = NULL;
}

int	bye(t_game *game)
{
	(void)game;//mlx exit
	exit (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		img_width;
	int		img_height;

	if (ac != 2)
		ft_error("ac error");
	init_game(&game);
	map_init(av[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 64 * game.map_wid, 64 * game.map_hei, "seojo's project");
	game.pl = mlx_xpm_file_to_image(game.mlx, "./img/seojo.xpm", &img_width, &img_height);
	game.wall = mlx_xpm_file_to_image(game.mlx, "./img/yeongo.xpm", &img_width, &img_height);
	game.exit = mlx_xpm_file_to_image(game.mlx, "./img/sielee.xpm", &img_width, &img_height);
	game.coin = mlx_xpm_file_to_image(game.mlx, "./img/coin.xpm", &img_width, &img_height);
	map_draw(&game);

	mlx_hook (game.win, X_EVENT_KEY_PRESS, 0, gps_check, &game);
	mlx_hook (game.win, X_EVENT_KEY_EXIT, 0, bye, &game);
	mlx_loop(game.mlx);
}


