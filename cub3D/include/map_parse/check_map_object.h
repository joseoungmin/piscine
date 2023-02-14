/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_object.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:43:05 by seojo             #+#    #+#             */
/*   Updated: 2023/02/12 20:12:34 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_OBJECT_H
# define CHECK_MAP_OBJECT_H

# include "libft.h"
# include "check_map_file_color.h"
# include "safe_func.h"
# include "world.h"

char	*split_filename(char *line);
char	*check_path(char *read_line);
char	*split_color(char *read_line, int *color);
int		check_color(char *read_line);
int		check_component(t_world *world, int fd);

#endif
