/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:21:15 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 02:01:56 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_map(char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		ft_error("open error");
	return (fd);
}


int	map_obj_check(char *map, int *objs)
{
	int	i;

	i = 1;
	while (map[++i])
	{
		if (map[i] == '1' || map[i] == '0')
			continue ;
		else if (map[i] == 'C')
			objs[COIN]++;
		else if (map[i] == 'E')
			objs[EXIT]++;
		else if (map[i] == 'P')
			objs[P]++;
		else
			return (1);
	}
	return (0);
}

void	map_malloc(t_game *game, int fd)
{
	int		i;
	char	c;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		game->map_cols = i * (i > game->map_cols);
		if (c == '\n')
		{
			game->map_rows++;
			i = 0;
		}
		else
			i++;
	}
	game->map_arr = (char **)malloc(sizeof(char *) * game->map_rows);
	if (!game->map_arr || game->map_cols == 0)
		ft_error("malloc error");
	i = -1;
	while (++i != game->map_cols)
	{
		game->map_arr[i] = (char *)malloc(sizeof(char *) * game->map_cols);
		if (!game->map_arr[i])
			ft_error("malloc error");	
	}
}

void	map_load(char *map, t_game *game, int fd)
{
	int		fd;
	char	*line;
	int		objs[3];
	int i;
	int j;

	objs[P] = 0;
	objs[COIN] = 0;
	objs[EXIT] = 0;  //bit mask
	fd = open_map(map);
	line = get_next_line(fd);
	game->map_wid = ft_strlen(line); // -1;
	i = 0;
	while (line)
	{
		game->map_hei++;
		if (map_obj_check(line, objs))
			ft_error("obj error");
		if (game_wid != ft_strlen(line))  // -1;
			ft_error("map width error");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (objs[P] != 1 || objs[COIN] < 1 || objs[EXIT] < 1)
		ft_error("object count error");
}
//배열에 담아서 그리기

//주변 벽 이 돌아가있는지 네모 체크

void	map_init(char *map, t_game *game)
{
	const int	map_name_len = ft_strlen(map);
	int			fd;

	if (map_name_len < 5 || ft_strncmp(map[map_name_len - 4], ".ber" ,4))
		ft_error(0);
	fd = open_map(map);
	map_malloc(game);
	close(fd);
	map_load(map, game, fd);
}
