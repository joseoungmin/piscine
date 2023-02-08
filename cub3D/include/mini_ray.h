/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:31:39 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 18:38:32 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RAY_H
# define MINI_RAY_H

# include <math.h>
# include <stdlib.h>
# include "map.h"
# include "error.h"

# define RAY_RANGE (M_PI / 3.0)
# define DOUBLE_MAX 1.797693e+308

typedef struct s_rtmp	t_rtmp;

struct	s_rtmp
{
	double	xinter;
	double	yinter;
	double	xstep;
	double	ystep;
	int		wall_hit;
	double	x_hit;
	double	y_hit;
	double	distance;
};

double	normalize_angle(double angle);
t_ray	*init_ray(double ray_angle);
int		is_wall(t_map *map, double x, double y);
double	d_b_points(double x1, double y1, double x2, double y2);
void	cal_distance(t_map *map, t_rtmp *hv);

#endif
