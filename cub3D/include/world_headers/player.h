/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:04:22 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 16:05:48 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player	t_player;

struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	double	move_speed;
	double	rot_speed;
	char	cardinal;
};

#endif
