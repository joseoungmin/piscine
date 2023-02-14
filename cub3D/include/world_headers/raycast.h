/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:53:29 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:05:15 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_raycast	t_raycast;
typedef struct s_draw		t_draw;

struct s_draw
{
	int		line_h;
	int		start;
	int		end;
	t_ivec	tex;
};

struct s_texture
{
	double	wall_x;
	t_card	type;
	double	step;
	double	pos;
};

struct s_raycast
{
	t_vec		ray;
	t_vec		side;
	t_vec		delta;
	t_ivec		block;
	t_ivec		step;
	double		cam_y;
	double		d;
	int			is_side;
};

#endif
