/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:30:56 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 18:31:25 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ray.h"

t_ray	*init_ray(double ray_angle)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		err_exit("init_ray : malloc failed");
	ray->ray_angle = normalize_angle(ray_angle);
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->hit_vert = 0;
	ray->facing_down = (ray->ray_angle > 0 && ray->ray_angle < M_PI);
	ray->facing_up = !ray->facing_down;
	ray->facing_right = (ray->ray_angle < 0.5 * M_PI || \
						ray->ray_angle > 1.5 * M_PI);
	ray->facing_left = !ray->facing_right;
	return (ray);
}

double	normalize_angle(double angle)
{
	if (angle >= 0)
	{
		while (angle >= M_PI * 2)
			angle -= M_PI * 2;
	}
	else
		while (angle <= 0)
			angle += M_PI * 2;
	return (angle);
}

int	is_wall(t_map *map, double x, double y)
{
	if (x <= 0 || y <= 0 || \
		x >= map->width * MINI_SCALE || \
		y >= map->height * MINI_SCALE)
		return (1);
	return (map->map[(int)(floor(y) / MINI_SCALE)] \
					[(int)(floor(x) / MINI_SCALE)] == '1');
}

double	d_b_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cal_distance(t_map *map, t_rtmp *hv)
{
	if (hv->wall_hit == 1)
		hv->distance = d_b_points((map->player->x * MINI_SCALE), \
				(map->player->y * MINI_SCALE), hv->x_hit, hv->y_hit);
	else
		hv->distance = DOUBLE_MAX;
}
