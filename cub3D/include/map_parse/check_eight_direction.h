/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eight_direction.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:43:50 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 15:30:07 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_EIGHT_DIRECTION_H
# define CHECK_EIGHT_DIRECTION_H

# include "error.h"
# include "world.h"

void	check_eight_directions(t_world *world, \
		char **map, int height, int width);

#endif
