/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:29:35 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:29:50 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*tmlx;

	tmlx = malloc(sizeof(t_mlx));
	if (!tmlx)
		err_exit("mlx malloc error");
	tmlx->mlx = mlx_init();
	if (!tmlx->mlx)
		err_exit("mlx_init error");
	tmlx->timg_main.img = mlx_new_image(tmlx->mlx, WIN_W, WIN_H);
	tmlx->timg_main.data = \
	(int *)mlx_get_data_addr(tmlx->timg_main.img, &tmlx->timg_main.bpp, \
	&tmlx->timg_main.line_len, &tmlx->timg_main.endian);
	tmlx->win = mlx_new_window(tmlx->mlx, WIN_W, WIN_H, "cub3D");
	return (tmlx);
}
