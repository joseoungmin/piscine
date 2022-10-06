/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:25:30 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 02:02:50 by seojo            ###   ########.fr       */
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

void	init_game(t_game *game)
{
	game->map_hei = 0;
	game->map_wid = 0;
	game->map_cols = 0;
	game->map_rows = 0;
	game->map_arr = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error(0);
	init_game(&game);
	map_init(av[1], &game);

	void	*mlx;
	void	*win;
	t_gps	gps;

	void	*img;
	void	*wall_img;
	void	*exit_img;

	int		img_width;
	int		img_height;


	gps_init(&gps);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "seojo's project");
	
	img = mlx_xpm_file_to_image(mlx, "./img/seojo.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "./img/yeongo.xpm", &img_width, &img_height);
	exit_img = mlx_xpm_file_to_image(mlx, "./img/sielee.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 128+64, 0);
	mlx_put_image_to_window(mlx, win, wall_img, 64, 0);
	mlx_put_image_to_window(mlx, win, exit_img, 128, 0);

	mlx_hook (win, X_EVENT_KEY_PRESS, 0, &gps_check, &gps);
	mlx_loop(mlx);
}


