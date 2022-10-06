/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:23:43 by seojo             #+#    #+#             */
/*   Updated: 2022/10/06 15:16:00 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum
{
	key_w = 1,
	key_a,
	key_s,
	key_d,
	key_esc,
	key_press,
	key_release,
};

typedef s_gps
{
	int	x;
	int	y;
}		t_gps;

#endif
