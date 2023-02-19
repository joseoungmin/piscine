/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:09:01 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 13:43:00 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clear_world.h"

void	clear_world(t_world *world)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(world->tex_path[i]);
		free(world->wall_tex[i]);
		free(world->tmlx->timg_wall_tex[i].img);
		free(world->tmlx->timg_wall_tex[i++].data);
	}
	i = 0;
	while (i < world->screen_h)
		free(world->screen_buf[i++]);
	free(world->screen_buf);
	i = 0;
	while (i < world->map_h)
		free(world->map[i++]);
	free(world->map);
	free(world->tmlx->timg_main.img);
	free(world->tmlx->timg_main.data);
	mlx_destroy_window(world->tmlx->mlx, world->tmlx->win);
}
