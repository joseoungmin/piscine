/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_object.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:43:05 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 19:49:30 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_OBJECT_H
# define CHECK_MAP_OBJECT_H
# include "libft.h"
# include "map.h"
# include "ft_open.h"

char	*split_filename(char *line);
char	*check_path(char *read_line);
char	*split_color(char *read_line, int *color);
int		check_color(char *read_line);
int		check_component(int fd, t_map *map);

#endif
