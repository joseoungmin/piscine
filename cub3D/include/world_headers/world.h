/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:10:14 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:08:45 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "key.h"
# include "enum_set.h"
# include "vector.h"
# include "tmlx.h"
# include "raycast.h"
# include "player.h"

# define WIN_W 1680
# define WIN_H 1050
# define DARKER 8355711
# define BASIC_CONFIG 6

typedef struct s_world		t_world;
typedef struct s_texture	t_texture;

typedef void				(*t_key_action)(t_world *world);

struct s_world
{
	t_mlx		*tmlx;
	t_raycast	rc;
	t_player	player;
	char		**map;
	int			map_h;
	int			map_w;
	int			**screen_buf;
	int			screen_w;
	int			screen_h;
	int			*wall_tex[4];
	int			wall_tex_n;
	char		*tex_path[4];
	int			floor;
	int			ceiling;
	int			keycode;
	double		z_buf[WIN_W];
};

#endif
