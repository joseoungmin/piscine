/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:26:33 by seojo             #+#    #+#             */
/*   Updated: 2023/01/31 16:27:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "map.h"

void	move_right(t_map *map);
void	move_left(t_map *map);
void	move_backward(t_map *map);
void	move_forward(t_map *map);

#endif
