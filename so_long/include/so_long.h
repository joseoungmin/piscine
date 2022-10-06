/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:23:43 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 01:19:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

# define X_EVENT_KEY_PRESS		2

/* Clicking on the RED cross on the window frame */
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

typedef struct s_game
{
	int		map_hei;
	int		map_wid;
	int		map_cols;
	int		map_rows;
	char	**map_arr;
}				t_game;

typedef struct s_gps
{
	int	x;
	int	y;
}				t_gps;

enum
{
	P,
	EXIT,
	COIN
};

#endif
