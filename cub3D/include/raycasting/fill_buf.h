/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:22:23 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 02:31:09 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_BUF_H
# define FILL_BUF_H

# include "world.h"
# include <math.h>
# include <stdlib.h>

void	wear_texture(t_world *world, t_raycast *rc, t_texture *tex, \
t_draw *dr);
int		get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr);
void	fill_buf(t_world *world, t_raycast *rc, t_texture *tex, int x);

#endif