/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:21:15 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 16:02:50 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_map(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		ft_error("open error");
	return (fd);
}

void	map_load(char *map, t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open_map(map);
	line = get_next_line(fd);
	if (!line)
		ft_error("gnl error");
	game->map_wid = ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		game->map_hei++;
		if (game->map_wid != (int)ft_strlen(line) - 1)
			ft_error("map width error");
		j = -1;
		while (++j < game->map_wid)
			game->map_arr[i][j] = line[j];
		game->map_arr[i++][j] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_init(char *map, t_game *game)
{
	const int	map_name_len = ft_strlen(map);
	int			fd;

	if (map_name_len < 5 || ft_strncmp(map + map_name_len - 4, ".ber", 4))
		ft_error("map error");
	fd = open_map(map);
	map_malloc(game, fd);
	close(fd);
	map_load(map, game);
	map_wall_check(game);
}

void	draw_pix(t_game *game, int i, int j)
{
	if (game->map_arr[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, \
				j * 64, i * 64);
	else if (game->map_arr[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, \
				j * 64, i * 64);
	else if (game->map_arr[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin, \
				j * 64, i * 64);
	else if (game->map_arr[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pl, \
				j * 64, i * 64);
		game->gps.x = j;
		game->gps.y = i;
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->ground, \
				j * 64, i * 64);
}

void	map_draw(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_rows)
	{
		j = -1;
		while (++j < game->map_cols)
			draw_pix(game, i, j);
	}
}
