/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:45:33 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 15:34:38 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_WORLD_H
# define SET_WORLD_H

# include "world.h"
# include "init_screen_buf.h"
# include "init_rc.h"
# include "check_hit.h"
# include "fill_buf.h"
# include "mlx.h"

void	world_on_screen(t_world *world, t_mlx *tmlx);
int		set_world(t_world *world);

#endif
