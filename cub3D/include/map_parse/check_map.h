/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:58:48 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 20:21:58 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H
# include "check_map_object.h"
# include "check_map_count_alloc.h"
# include "check_eight_direction.h"
# include "set_player.h"
# include "key_toggle.h"

void	print_map_argument_err(t_map_err err_num);
t_map	*check_and_return_map(char *map_file);

#endif
