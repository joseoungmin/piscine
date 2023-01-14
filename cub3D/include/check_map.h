/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:58:48 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 16:54:02 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include "libft.h"
# include "map.h"
# include "check_map_object.h"
# include "ft_open.h"

void	print_map_argument_err(t_map_err err_num);
t_map	*check_and_return_map(char *map_file);

#endif
