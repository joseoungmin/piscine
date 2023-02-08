/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:33 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 20:21:01 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_mini_ray.h"

void	cal_ray(t_map *map, t_rtmp *hv)
{
	double	n_touch_x;
	double	n_touch_y;

	n_touch_x = hv->xinter;
	n_touch_y = hv->yinter;
	while (n_touch_x >= 0 && n_touch_x <= (map->width * MINI_SCALE) && \
			n_touch_y >= 0 && n_touch_y <= (map->height * MINI_SCALE))
	{
		if (is_wall(map, n_touch_x, n_touch_y - map->ray->facing_up))
		{
			hv->wall_hit = 1;
			hv->x_hit = n_touch_x;
			hv->y_hit = n_touch_y;
			break ;
		}
		else
		{
			n_touch_x += hv->xstep;
			n_touch_y += hv->ystep;
		}
	}
	cal_distance(map, hv);
}

void	horz_ray(t_map *map, t_rtmp *horz)
{
	horz->wall_hit = 0;
	horz->x_hit = 0;
	horz->y_hit = 0;
	horz->yinter = floor(map->player->y) * MINI_SCALE;
	horz->yinter += (map->ray->facing_down > 0) * MINI_SCALE;
	horz->xinter = (map->player->x * MINI_SCALE) + \
					(horz->yinter - (map->player->y * MINI_SCALE)) / \
					tan(map->ray->ray_angle);
	horz->ystep = MINI_SCALE;
	horz->ystep *= -1 * (map->ray->facing_up) + 1 * !(map->ray->facing_up);
	horz->xstep = MINI_SCALE / tan(map->ray->ray_angle);
	horz->xstep *= -1 * (map->ray->facing_left && horz->xstep > 0) \
					+ 1 * !(map->ray->facing_left && horz->xstep > 0);
	horz->xstep *= -1 * (map->ray->facing_right && horz->xstep < 0) \
					+ 1 * !(map->ray->facing_right && horz->xstep < 0);
	cal_ray(map, horz);
	horz->xstep *= -1 * (map->ray->facing_right && horz->xstep < 0) \
					+ 1 * !(map->ray->facing_right && horz->xstep < 0);
}

void	vert_ray(t_map *map, t_rtmp *vert)
{
	vert->wall_hit = 0;
	vert->x_hit = 0;
	vert->y_hit = 0;
	vert->xinter = floor(map->player->x) * MINI_SCALE;
	vert->xinter += (map->ray->facing_right > 0) * MINI_SCALE;
	vert->yinter = (map->player->y * MINI_SCALE) + \
					(vert->xinter - (map->player->x * MINI_SCALE)) * \
					tan(map->ray->ray_angle);
	vert->xstep = MINI_SCALE;
	vert->xstep *= -1 * (map->ray->facing_left > 0) \
					+ 1 * !(map->ray->facing_left > 0);
	vert->ystep = MINI_SCALE * tan(map->ray->ray_angle);
	vert->ystep *= -1 * (map->ray->facing_up && vert->ystep > 0) \
					+ 1 * !(map->ray->facing_up && vert->ystep > 0);
	vert->ystep *= -1 * (map->ray->facing_down && vert->ystep < 0) \
					+ 1 * !(map->ray->facing_down && vert->ystep < 0);
	cal_ray(map, vert);
}

void	draw_line(t_map *map)
{
	double	ray_x;
	double	ray_y;
	double	dx;
	double	dy;
	double	max_value;

	ray_x = map->player->x * MINI_SCALE;
	ray_y = map->player->y * MINI_SCALE;
	dx = map->ray->wall_hit_x - (map->player->x * MINI_SCALE);
	dy = map->ray->wall_hit_y - (map->player->y * MINI_SCALE);
	max_value = fmax(fabs(dx), fabs(dy));
	dx /= max_value;
	dy /= max_value;
	while (1)
	{
		if (!is_wall(map, ray_x, ray_y))
			map->world->data[(int)(WINDOW_WIDTH \
					* floor(ray_y) + floor(ray_x))] = COL_RED;
		else
			break ;
		ray_x += dx;
		ray_y += dy;
	}
}

void	draw_one_ray(t_map *map, double angle)
{
	t_rtmp	horz;
	t_rtmp	vert;

	map->ray = init_ray(angle);
	horz_ray(map, &horz);
	vert_ray(map, &vert);
	if (vert.distance < horz.distance)
	{
		map->ray->wall_hit_x = vert.x_hit;
		map->ray->wall_hit_y = vert.y_hit;
		map->ray->distance = vert.distance;
		map->ray->hit_vert = 1;
	}
	else
	{
		map->ray->wall_hit_x = horz.x_hit;
		map->ray->wall_hit_y = horz.y_hit;
		map->ray->distance = horz.distance;
	}
	draw_line(map);
}

void	draw_mini_ray(t_map *map)
{
	double	angle;
	double	max_angle;

	map->player->rot_angle = atan2(map->player->dir_y, map->player->dir_x);
	angle = map->player->rot_angle;
	max_angle = map->player->rot_angle + (RAY_RANGE / 2.0);
	while (angle <= max_angle)
	{
		draw_one_ray(map, angle);
		draw_one_ray(map, angle - (RAY_RANGE / 2.0));
		angle += (RAY_RANGE / 2.0) / ((RAY_COUTNT - 1) / 2.0);
	}
}
