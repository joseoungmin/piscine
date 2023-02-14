/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:21:33 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:39:58 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fill_buf.h"

void	wear_texture(t_world *world, t_raycast *rc, t_texture *tex, \
t_draw *dr)
{
	tex->wall_x -= floor(tex->wall_x);
	dr->tex.x
		= (int)(tex->wall_x * (double)world->tmlx->timg_wall_tex[tex->type].w);
	if ((rc->is_side == 0 && rc->ray.x < 0)
		|| (rc->is_side == 1 && rc->ray.y > 0))
	{
		dr->tex.x = world->tmlx->timg_wall_tex[tex->type].w - dr->tex.x - 1;
	}
	tex->step = 1.0 * world->tmlx->timg_wall_tex[tex->type].h / dr->line_h;
	tex->pos
		= (dr->start - world->screen_h / 2.0 + dr->line_h / 2.0) * tex->step;
}

int	get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	color = 0;
	dr->tex.y = (int)tex->pos & (world->tmlx->timg_wall_tex[tex->type].h - 1);
	tex->pos += tex->step;
	color = world->wall_tex[tex->type] \
			[(int)(world->tmlx->timg_wall_tex[tex->type].h
			* dr->tex.y + dr->tex.x)];
	if (rc->is_side == 1)
		color = (color >> 1) & DARKER;
	return (color);
}

void	fill_buf(t_world *world, t_raycast *rc, t_texture *tex, int x)
{
	t_draw	dr;
	int		y;

	dr.line_h = (int)(world->screen_h / rc->d);
	dr.start = (-dr.line_h / 2) + (world->screen_h / 2);
	dr.end = (dr.line_h / 2) + (world->screen_h / 2);
	if (dr.start < 0)
		dr.start = 0;
	if (dr.end >= (int)world->screen_h)
		dr.end = (int)world->screen_h - 1;
	if (world->wall_tex[tex->type] != NULL)
		wear_texture(world, rc, tex, &dr);
	y = dr.start;
	while ((int)y < dr.end)
	{
		world->screen_buf[y][x] = get_color(world, rc, tex, &dr);
		y++;
	}
}
