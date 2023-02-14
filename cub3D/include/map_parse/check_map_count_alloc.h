/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_count_alloc.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:46:29 by seojo             #+#    #+#             */
/*   Updated: 2023/02/12 20:12:34 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_COUNT_ALLOC_H
# define CHECK_MAP_COUNT_ALLOC_H

# include "ft_open.h"
# include "libft.h"
# include "safe_func.h"
# include "world.h"

void	count_map(t_world *world, int fd);
int		reopen_fd(char *filename, int file_height);
void	map_alloc(t_world *world);

#endif
