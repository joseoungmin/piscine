/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:41:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 14:44:06 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	init_game(t_game *game)
{
	game->coin_cnt = 0;
	game->map_wid = 0;
	game->map_hei = 0;
	game->map_cols = 0;
	game->map_rows = 0;
	game->move_cnt = 0;
	game->map_arr = NULL;
}

int	bye(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}
