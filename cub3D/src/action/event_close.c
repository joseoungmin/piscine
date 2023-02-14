/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:16:18 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:36:43 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "event_close.h"

void	event_close(t_world *world)
{
	mlx_destroy_window(world->tmlx->mlx, world->tmlx->win);
	exit(0);
}
