/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:43:07 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 14:34:53 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_world.h"

void	background(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	while (y < world->screen_h / 2)
	{
		x = 0;
		while (x < world->screen_w)
		{
			world->screen_buf[y][x] = world->ceiling;
			world->screen_buf[world->screen_h - y - 1][x] = world->floor;
			x++;
		}
		y++;
	}
}

void	world_on_screen(t_world *world, t_mlx *tmlx)
{
	int	w;
	int	h;

	h = 0;
	while (h < world->screen_h)
	{
		w = 0;
		while (w < world->screen_w)
		{
			tmlx->timg_main.data[(h * world->screen_w) + w] \
			= world->screen_buf[h][w];
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->timg_main.img, 0, 0);
}

void	step_dir(t_player *p, t_raycast *rc)
{
	if (rc->ray.x < 0)
	{
		rc->step.x = -1;
		rc->side.x = (p->pos.x - rc->block.x) * rc->delta.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side.x = (rc->block.x + 1.0 - p->pos.x) * rc->delta.x;
	}
	if (rc->ray.y < 0)
	{
		rc->step.y = -1;
		rc->side.y = (p->pos.y - rc->block.y) * rc->delta.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side.y = (rc->block.y + 1.0 - p->pos.y) * rc->delta.y;
	}
}

int	set_world(t_world *world)
{
	t_raycast	rc;
	t_texture	tex;
	int			x;

	x = 0;
	background(world);
	while (x < world->screen_w)
	{
		init_rc(world, &rc, x);
		step_dir(&world->player, &rc);
		check_hit(world, &world->player, &rc, &tex);
		fill_buf(world, &rc, &tex, x);
		x++;
	}
	return (0);
}
