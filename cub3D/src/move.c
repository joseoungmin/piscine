/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:13 by seojo             #+#    #+#             */
/*   Updated: 2023/01/31 16:37:32 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

int	is_blank(char rocation)
{
	if (rocation == '1')
		return (0);
	return (1);
}

void	move_right(t_map *map)
{
	t_player	*p;

	p = map->player;
	if (is_blank(map->map[(int)p->y][(int)(p->x - p->dir_y * p->move_speed)]))
		p->x -= p->dir_y * p->move_speed;
	if (is_blank(map->map[(int)(p->y + p->dir_x * p->move_speed)][(int)p->x]))
		p->y += p->dir_x * p->move_speed;
}

void	move_left(t_map *map)
{
	t_player	*p;

	p = map->player;
	if (is_blank(map->map[(int)p->y][(int)(p->x + p->dir_y * p->move_speed)]))
		p->x += p->dir_y * p->move_speed;
	if (is_blank(map->map[(int)(p->y - p->dir_x * p->move_speed)][(int)p->x]))
		p->y -= p->dir_x * p->move_speed;
}

void	move_backward(t_map *map)
{
	t_player	*p;

	p = map->player;
	if (is_blank(map->map[(int)p->y][(int)(p->x - p->dir_x * p->move_speed)]))
		p->x -= p->dir_x * p->move_speed;
	if (is_blank(map->map[(int)(p->y - p->dir_y * p->move_speed)][(int)p->x]))
		p->y -= p->dir_y * p->move_speed;
}

void	move_forward(t_map *map)
{
	t_player	*p;

	p = map->player;
	if (is_blank(map->map[(int)p->y][(int)(p->x + p->dir_x * p->move_speed)]))
		p->x += p->dir_x * p->move_speed;
	if (is_blank(map->map[(int)(p->y + p->dir_y * p->move_speed)][(int)p->x]))
		p->y += p->dir_y * p->move_speed;
}
