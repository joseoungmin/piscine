/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:25:00 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 01:35:17 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_TOGGLE_H
# define KEY_TOGGLE_H

# include "move.h"
# include "find_key.h"
# include <stdlib.h>
# include <math.h>

int	key_press(int key, t_world *world);
int	key_release(int key, t_world *world);

#endif
