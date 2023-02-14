/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:55 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 01:32:01 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "key_toggle.h"

int	key_press(int key, t_world *world)
{
	world->keycode |= (1 << find_key(key));
	return (0);
}

int	key_release(int key, t_world *world)
{
	world->keycode &= ~(1 << find_key(key));
	return (0);
}
