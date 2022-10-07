/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:23:43 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 16:35:58 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC			53
# define KEY_R				15
# define KEY_RETURN			36
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124

typedef struct s_gps
{
	int	x;
	int	y;
}				t_gps;

typedef struct s_game
{
	void	*wall;
	void	*coin;
	void	*exit;
	void	*ground;
	void	*pl;
	void	*win;
	void	*mlx;
	int		coin_cnt;
	int		move_cnt;
	int		map_hei;
	int		map_wid;
	int		map_cols;
	int		map_rows;
	char	**map_arr;
	t_gps	gps;
}				t_game;

enum
{
	P,
	EXIT,
	COIN
};

void	ft_error(char *msg);
void	map_init(char *map, t_game *game);
void	map_draw(t_game *game);
int		move_check(int key, t_game *game);
int		bye(t_game *game);
void	init_game(t_game *game);
void	map_malloc(t_game *game, int fd);
void	map_wall_check(t_game *game);

#endif
