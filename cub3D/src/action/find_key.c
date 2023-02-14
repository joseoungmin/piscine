/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:31:16 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:27:04 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_key.h"

int	find_key(const int keycode)
{
	int			i;
	const int	key_table[] = {KEY_W, KEY_A, KEY_S, KEY_D, KEY_ARROW_L,
		KEY_ARROW_R, KEY_ESC};

	i = 0;
	while (i < 7)
	{
		if (key_table[i] == keycode)
			break ;
		i++;
	}
	return (i);
}
