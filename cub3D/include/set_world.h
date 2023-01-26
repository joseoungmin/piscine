/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:52:31 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 23:23:02 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_WORLD_H
# define SET_WORLD_H
# include <mlx.h>
# include "map.h"
# include "world.h"
# include "error.h"
# include "set_player.h"
# include "render_map.h"

void	set_world(t_map *map);

#endif
