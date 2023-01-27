/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 19:14:07 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	bye(void)
{
	system("Leaks cub3D");
}

void	print_map(t_map *map)
{
	int	y;
	int	x;

	printf("\n========== PRINT OBJ ==========\n\n");
	printf("NO = [%s]\n", map->no_path);
	printf("SO = [%s]\n", map->so_path);
	printf("WE = [%s]\n", map->we_path);
	printf("EA = [%s]\n", map->ea_path);
	printf("F = [%x]\n", map->floor);
	printf("C = [%x]\n", map->ceiling);
	printf("player direction = %c\n", map->direction);
	printf("player x = %f\n", map->player->x);
	printf("player y = %f\n", map->player->y);
	printf("\n========== PRINT MAP ==========\n\n");
	y = 0;
	while(y < map->height)
	{
		x = 0;
		while(x < map->width)
			printf("%c", map->map[y][x++]);
		y++;
		printf("\n");
	}
	printf("\n ========== END MAP ========== \n");
}

int	main(int ac, char **av)
{
	t_map	*map;

	check_argument(ac, av);
	map = check_and_return_map(av[1]);
	set_world(map);
//	print_map(map); //print map;

	mlx_hook(map->world->win, X_KEY_PRESS, 1L << 0, &key_press, map);
	mlx_hook(map->world->win, X_KEY_RELEASE, 1L << 0, &key_release, map);

	mlx_loop_hook(map->world->mlx, &ft_loop, map);
	mlx_loop(map->world->mlx);
	free_map(map);
//	atexit(bye);
	return (0);
}
