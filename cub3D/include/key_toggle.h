/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:25:00 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 20:19:53 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_TOGGLE_H
# define KEY_TOGGLE_H
# include "map.h"
# include <stdlib.h>

t_key	*init_key(void);
void	move_check(t_map *map);
int		key_press(int keycode, t_map *map);
int		key_release(int keycode, t_map *map);

#endif