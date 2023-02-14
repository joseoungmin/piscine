/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:17:27 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 02:20:41 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_HIT_H
# define CHECK_HIT_H

# include "world.h"

void	check_hit(t_world *world, t_player *p, t_raycast *rc, t_texture *tex);

#endif