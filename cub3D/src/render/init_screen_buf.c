/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:50:18 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 10:07:04 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "init_screen_buf.h"

void	init_screen_buf(t_world *world)
{
	int	w;
	int	h;

	h = 0;
	while (h < world->screen_h)
	{
		w = 0;
		while (w < world->screen_w)
		{
			world->screen_buf[h][w] = 0;
			w++;
		}
		h++;
	}
}
