/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/24 00:06:32 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	bye(void)
{
	system("Leaks cub3D");
}

int	main(int ac, char **av)
{
	t_map	*map;

	check_argument(ac, av);
	map = check_and_return_map(av[1]);
	set_world(map);

	/// map print ///
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
	for (int y=0; y < map->height; y++)
	{
		for(int x=0; x < map->width; x++)
			printf("%c", map->map[y][x]);
		printf("\n");
	}
	printf("\n ========== END MAP ========== \n\n");
/// map pirnt ///
	free_map(map);
//	atexit(bye);
	return (0);
}
