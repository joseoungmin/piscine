/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:57:53 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 19:32:04 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MAP_H
# define RENDER_MAP_H
# include "map.h"
# include "mlx.h"
# include "error.h"
# include <stdlib.h>

void	fill_rectangle(t_map *map, int x, int y, int color);
void	render_map(t_map *map);
void	world_malloc(t_map *map);

#endif