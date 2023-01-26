/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 12:29:09 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define MINI_SCALE 1
#define TILE_SIZE 20
#define MAP_NUM_ROWS 12
#define MAP_NUM_COLS 20

#define WINDOW_W (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_H (MAP_NUM_ROWS * TILE_SIZE)

void	bye(void)
{
	system("Leaks cub3D");
}


void	fill_rectangle(t_map *map, int x, int y, int color)
{
	int		i;
	int		j;

	j = 0;
	while (j < (int)(MINI_SCALE * TILE_SIZE))
	{
		i = 0;
		while (i < (int)(MINI_SCALE * TILE_SIZE))
		{
			map->world->data[(int)(MINI_SCALE * map->width * TILE_SIZE) * (y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

void	render_map(t_map *map)
{
	int		col;
	int		row;

	map->world->data = (int *)mlx_get_data_addr(map->world->img, &map->world->bpp, &map->world->line_len, &map->world->endian);
	row = 0;
	while (row < map->height - 1)
	{
		col = 0;
		while (col < map->width - 1)
		{
			printf("%c", map->map[row][col]);
			if (map->map[row][col] == '1')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), (int)(row * TILE_SIZE * MINI_SCALE), 0x000000);
			else if (map->map[row][col] == '0')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), (int)(row * TILE_SIZE * MINI_SCALE), 0xFFFFFF);
			col++;
		}
		printf("\n");
		row++;
	}
	mlx_put_image_to_window(map->world->mlx, map->world->win, map->world->img, (int)(map->width * TILE_SIZE * (1 -  MINI_SCALE)), (int)(map->height * TILE_SIZE * (1 - MINI_SCALE)));
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
	printf("\n ========== END MAP ========== \n");
/// map pirnt ///

	map->world = malloc(sizeof(t_world));
	if (map->world == NULL)
		err_exit("set_image : malloc fail");
	map->world->mlx = mlx_init();
	map->world->win = mlx_new_window(map->world->mlx, map->width * TILE_SIZE, map->height * TILE_SIZE, "cub3D");
	map->world->img = mlx_new_image(map->world->mlx, (int)(MINI_SCALE * map->width * TILE_SIZE), (int)(MINI_SCALE * map->height * TILE_SIZE));
	render_map(map);
	mlx_loop(map->world->mlx);


	// mlx hook and open window
//	mlx_hook(world->win, X_KEY_PRESS, 0, move_check, //structere);
//	mlx_hook(world->win, X_KEY_EXIT, 0, endgame, //structere);
//	mlx_loop(world->mlx);

	free_map(map);
//	atexit(bye);
	return (0);
}
