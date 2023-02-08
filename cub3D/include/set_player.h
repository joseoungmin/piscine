/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:22:01 by seojo             #+#    #+#             */
/*   Updated: 2023/01/28 15:51:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PLAYER_H
# define SET_PLAYER_H
# include "map.h"
# include "error.h"
# include <stdlib.h>

# define COL_BLU 0x0000FF

int         draw_player(t_map *map);
void        set_player(t_map *map);

#endif
