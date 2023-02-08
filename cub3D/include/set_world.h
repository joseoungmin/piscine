/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:52:31 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 13:35:24 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_WORLD_H
# define SET_WORLD_H
# include "set_player.h"
# include "render_map.h"
# include "key_toggle.h"
# include "init.h"
# include "draw_mini_ray.h"

void	set_world(t_map *map);
int		ft_loop(t_map *map);

#endif
