/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:25:30 by seojo             #+#    #+#             */
/*   Updated: 2022/10/06 15:47:23 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	gps_init(t_gps *gps)
{
	gps->x = 3;
	gps->y = 4;
}

int	gps_check(int key, t_gps *gps)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP)
		gps->y++;
	else if (key == KEY_A || key == KEY_LEFT)
		gps->x--;
	else if (key == KEY_S || key == KEY_DOWN)
		gps->y--;
	else if (key == KEY_D || key == KEY_RIGHT)
		gps->x++;
	printf("x: %d, y: %d\n", gps->x, gps->y);
	return (0);
}	

int	main(void)
{
	void	*mlx;
	void	*win;
	t_gps	gps;

	gps_init(&gps);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "seojo's project");
	mlx_hook (win, X_EVENT_KEY_PRESS, 0, &gps_check, &gps);
	mlx_loop(mlx);
}
