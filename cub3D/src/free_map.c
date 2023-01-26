/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:05:10 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 22:18:36 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "free_map.h"

void	free_map(t_map *map)
{
	int	y;

	safe_free(map->player);
	safe_free(map->world);
	safe_free(map->no_path);
	safe_free(map->so_path);
	safe_free(map->we_path);
	safe_free(map->ea_path);
	y = 0;
	while (y < map->height)
		safe_free(map->map[y++]);
	safe_free(map->map);
	safe_free(map);
}
