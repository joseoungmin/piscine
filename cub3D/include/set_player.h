/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:22:01 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 23:26:52 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PLAYER_H
# define SET_PLAYER_H
# include "map.h"
# include "key.h"

int     draw_player(t_map *map);
void    set_player(t_map *map);

#endif