/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/02/20 15:56:43 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	print_map(t_world *world)
{
	int	y;
	int	x;

	printf("\n========== PRINT OBJ ==========\n\n");
	printf("NO = [%s]\n", world->tex_path[NO]);
	printf("SO = [%s]\n", world->tex_path[SO]);
	printf("WE = [%s]\n", world->tex_path[WE]);
	printf("EA = [%s]\n", world->tex_path[EA]);
	printf("F = [%x]\n", world->floor);
	printf("C = [%x]\n", world->ceiling);
	printf("player direction = %c\n", world->player.cardinal);
	printf("player x = %f\n", world->player.pos.x);
	printf("player y = %f\n", world->player.pos.y);
	printf("\n========== PRINT MAP ==========\n\n");
	y = 0;
	while (y < world->map_h)
	{
		x = 0;
		while (x < world->map_w)
			printf("%c", world->map[y][x++]);
		y++;
		printf("\n");
	}
	printf("\n ========== END MAP ========== \n");
}

int	main(int ac, char **av)
{
	t_world	*world;

	check_argument(ac, av);
	world = init_world();
	check_map(world, av[1]);
	init_render(world);
	render(world);
	clear_world(world);
	return (0);
}
