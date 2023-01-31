/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:50:31 by seojo             #+#    #+#             */
/*   Updated: 2023/02/01 01:17:08 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"
int g_color = 0xFF0000;

#define RAY_RANGE (M_PI / 3.0)
#define RAY_COUTNT 121
#include <limits.h>
#include <float.h>
typedef struct	s_rtmp
{
	double	xinter;
	double	yinter;
	double	xstep;
	double	ystep;
	int		wall_hit;
	double	x_hit;
	double	y_hit;
	double	distance;
}		t_rtmp;

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
	return angle;
}

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
	ray->facing_down = ray->ray_angle > 0 && ray->ray_angle < M_PI;
	ray->facing_up = !ray->facing_down;
	ray->facing_right = ray->ray_angle < 0.5 * M_PI || ray->ray_angle > 1.5 * M_PI;
	ray->facing_left = !ray->facing_right;
	return (ray);
}

#include <stdio.h>
int	is_wall(t_map *map, double x, double y)
{
	int	xX;
	int	yY;

	if (x <= 0 || y <= 0 || x >= map->width * TILE_SIZE || y >= map->height * TILE_SIZE)
		return (1);
	xX = (int)floor(x / TILE_SIZE);
	yY = (int)floor(y / TILE_SIZE);
	return (map->map[yY][xX] == '1');
}

double	d_b_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cal_distance(t_map *map, t_rtmp *hv)
{
	if (hv->wall_hit == 1)
		hv->distance = d_b_points((map->player->x * TILE_SIZE), (map->player->y * TILE_SIZE), hv->x_hit, hv->y_hit);
	else
		hv->distance = DBL_MAX;
}

void	cal_ray(t_map *map, t_rtmp *hv)
{
	double	n_touch_x;
	double	n_touch_y;

	n_touch_x = hv->xinter;
	n_touch_y = hv->yinter;
	while (n_touch_x >= 0 && n_touch_x <= (map->width * TILE_SIZE) && n_touch_y >= 0 && n_touch_y <= (map->height * TILE_SIZE))
	{
		if (is_wall(map, n_touch_x, n_touch_y - (map->ray->facing_up ? 1 : 0)))
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
	horz->yinter = floor(map->player->y) * TILE_SIZE;
	horz->yinter += map->ray->facing_down ? TILE_SIZE : 0;
	horz->xinter = (map->player->x * TILE_SIZE) + (horz->yinter - (map->player->y * TILE_SIZE)) / tan(map->ray->ray_angle);
	horz->ystep = TILE_SIZE;
	horz->ystep *= map->ray->facing_up ? -1 : 1;
	horz->xstep = TILE_SIZE / tan(map->ray->ray_angle);
	horz->xstep *= (map->ray->facing_left && horz->xstep > 0) ? -1 : 1;
	horz->xstep *= (map->ray->facing_right && horz->xstep < 0) ? -1 : 1;
	cal_ray(map, horz);
}

void	vert_ray(t_map *map, t_rtmp * vert)
{
	vert->wall_hit = 0;
	vert->x_hit = 0;
	vert->y_hit = 0;
	vert->xinter = floor(map->player->x) * TILE_SIZE;
	vert->xinter += map->ray->facing_right ? TILE_SIZE : 0;
	vert->yinter = (map->player->y * TILE_SIZE) + (vert->xinter - (map->player->x * TILE_SIZE)) * tan(map->ray->ray_angle);
	vert->xstep = TILE_SIZE;
	vert->xstep *= map->ray->facing_left ? -1 : 1; 
	vert->ystep = TILE_SIZE * tan(map->ray->ray_angle);
	vert->ystep *= (map->ray->facing_up && vert->ystep > 0) ? -1 : 1;
	vert->ystep *= (map->ray->facing_down && vert->ystep < 0) ? -1 : 1;
	cal_ray(map, vert);
}

void	draw_line(t_map *map)
{
	double	ray_x;
	double	ray_y;
	double	dx;
	double	dy;
	double	max_value;

	ray_x = map->player->x * TILE_SIZE;
	ray_y = map->player->y * TILE_SIZE;
	dx = map->ray->wall_hit_x - (map->player->x * TILE_SIZE);
	dy = map->ray->wall_hit_y - (map->player->y * TILE_SIZE);
	max_value = fmax(fabs(dx), fabs(dy));
	dx /= max_value;
	dy /= max_value;
	while (1)
	{
		if (!is_wall(map, ray_x, ray_y))
		{
			map->world->data[(map->width * TILE_SIZE) * \
				(int)floor(ray_y) + (int)floor(ray_x)] = g_color;
		}
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

void	draw_ray(t_map *map)
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

int	ft_loop(t_map *map)
{
	render_map(map);
	draw_player(map);
	draw_ray(map);
	move_check(map);
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, \
			(int)(map->width * TILE_SIZE * (1 - MINI_SCALE)), \
			(int)(map->height * TILE_SIZE * (1 - MINI_SCALE)));
	return (0);
}

void	set_world(t_map *map)
{
	init_world(map);
	render_map(map);
	map->player->img = mlx_new_image(map->world->mlx, \
		(int)(MINI_SCALE * map->width * TILE_SIZE), \
		(int)(MINI_SCALE * map->height * TILE_SIZE));
	set_player(map);
	draw_player(map);
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, \
		(int)(map->width * TILE_SIZE * (1 - MINI_SCALE)), \
		(int)(map->height * TILE_SIZE * (1 - MINI_SCALE)));
}
