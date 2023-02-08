/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:47:23 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 14:33:22 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "world.h"
# include "player.h"
# include "key.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MINI_SCALE 8
# define PLAYER_THICKNESS 5

typedef enum e_bool	t_bool;
typedef enum e_color	t_color;
typedef struct s_map	t_map;

enum e_bool
{
	FALSE = 0,
	TRUE = 1,
};

enum e_color
{
	RED = 0,
	GREEN = 1,
	BLUE = 2,
};

typedef struct	s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		hit_vert;
	int		facing_down;
	int		facing_up;
	int		facing_right;
	int		facing_left;
}	t_ray;

struct s_map
{
	t_player	*player;
	t_world		*world;
    t_key       *key;
	t_ray		*ray;
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
