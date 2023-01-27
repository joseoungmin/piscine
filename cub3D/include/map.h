/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:47:23 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 19:32:50 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "world.h"
# include "player.h"
# include "key.h"
# define TILE_SIZE 20
# define MINI_SCALE 1
# define PLAYER_THICKNESS 5
typedef enum e_map_err	t_map_err;
typedef struct s_map	t_map;

enum e_map_err
{
	FALSE = 0,
	TRUE = 1,
	RED = 0,
	GREEN = 1,
	BLUE = 2,
};

struct s_map
{
	t_player	*player;
	t_world		*world;
    t_key       *key;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	int			floor;
	int			ceiling;
	int			width;
	int			height;
	char		direction;
};

#endif
