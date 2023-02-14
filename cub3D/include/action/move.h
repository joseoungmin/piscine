/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:26:33 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 15:33:45 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "world.h"

enum
{
	WALL = '1'
};

void		move_right(t_world *world);
void		move_left(t_world *world);
void		move_backward(t_world *world);
void		move_foreward(t_world *world);

#endif
