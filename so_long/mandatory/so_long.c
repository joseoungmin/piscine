/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:25:30 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 14:43:17 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	game.win = mlx_new_window(game.mlx, 64 * game.map_wid, 64 * \
			game.map_hei, "seojo's project");
	game.pl = mlx_xpm_file_to_image(game.mlx, "./img/seojo.xpm", \
			&img_width, &img_height);
	game.wall = mlx_xpm_file_to_image(game.mlx, "./img/yeongo.xpm", \
			&img_width, &img_height);
	game.exit = mlx_xpm_file_to_image(game.mlx, "./img/sielee.xpm", \
			&img_width, &img_height);
	game.coin = mlx_xpm_file_to_image(game.mlx, "./img/coin.xpm", \
			&img_width, &img_height);
	game.ground = mlx_xpm_file_to_image(game.mlx, "./img/ground.xpm", \
			&img_width, &img_height);
	map_draw(&game);
	mlx_hook (game.win, X_EVENT_KEY_PRESS, 0, move_check, &game);
	mlx_hook (game.win, X_EVENT_KEY_EXIT, 0, bye, &game);
	mlx_loop(game.mlx);
}
