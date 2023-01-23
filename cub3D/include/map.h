/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:47:23 by seojo             #+#    #+#             */
/*   Updated: 2023/01/23 23:57:51 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_map_err	t_map_err;
typedef struct s_map	t_map;
typedef struct s_player	t_player;

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

struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
};

#endif
