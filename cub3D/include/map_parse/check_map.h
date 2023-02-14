/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:58:48 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 15:30:29 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include "check_map_object.h"
# include "check_map_count_alloc.h"
# include "check_eight_direction.h"
# include "world.h"

void	check_map(t_world *world, char *map_file);

#endif
