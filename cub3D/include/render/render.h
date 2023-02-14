/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:57:53 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:32:06 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "world.h"
# include "mlx.h"
# include "key_toggle.h"
# include "action.h"
# include "set_world.h"
# include "event_red_cross.h"

void	render(t_world *world);

#endif
