/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_count_alloc.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:46:29 by seojo             #+#    #+#             */
/*   Updated: 2023/01/15 14:57:33 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_COUNT_ALLOC_H
# define CHECK_MAP_COUNT_ALLOC_H
# include "map.h"
# include "ft_open.h"
# include "libft.h"

void	count_map(int fd, t_map *map);
int		reopen_fd(char *filename, int file_height);
void	map_alloc(t_map *map);

#endif
