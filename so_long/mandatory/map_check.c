/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:52:16 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 17:40:08 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_obj_check(char c, int *objs)
{
	if (c == '1' || c == '0' || c == '\n')
		;
	else if (c == 'C')
		objs[COIN]++;
	else if (c == 'E')
		objs[EXIT]++;
	else if (c == 'P')
		objs[P]++;
	else
		return (1);
	return (0);
}

void	map_size_objs_check(t_game *game, int fd)
{
	int		i;
	char	c;
	int		objs[3];

	objs[P] = 0;
	objs[COIN] = 0;
	objs[EXIT] = 0;
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (map_obj_check(c, objs))
			ft_error("objs error");
		if (game->map_cols < i)
			game->map_cols = i;
		if (c == '\n')
		{
			game->map_rows++;
			i = 0;
		}
		else
			i++;
	}
	if (objs[P] != 1 || objs[COIN] < 1 || objs[EXIT] < 1)
		ft_error("object count error");
	game->coin_cnt = objs[COIN];
}

void	map_malloc(t_game *game, int fd)
{
	int	i;

	map_size_objs_check(game, fd);
	if (game->map_rows > 21 || game->map_cols > 40)
		ft_error("map size too big");
	game->map_arr = ft_calloc(game->map_rows + 1, sizeof(char *));
	if (!game->map_arr)
		ft_error("malloc error");
	i = -1;
	while (++i < game->map_rows + 1)
	{
		game->map_arr[i] = ft_calloc(game->map_cols + 1, sizeof(char *));
		if (!game->map_arr[i])
			ft_error("malloc error");
	}
}

void	map_wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_arr[0][i])
		if (game->map_arr[0][i++] != '1')
			ft_error("wall error1");
	i = 0;
	while (game->map_arr[i][0])
		if (game->map_arr[i++][0] != '1')
			ft_error("wall error2");
	i = 0;
	while (game->map_arr[i][game->map_cols - 1])
		if (game->map_arr[i++][game->map_cols - 1] != '1')
			ft_error("wall error3");
	i = 0;
	while (game->map_arr[game->map_rows - 1][i])
		if (game->map_arr[game->map_rows - 1][i++] != '1')
			ft_error("wall error4");
}
