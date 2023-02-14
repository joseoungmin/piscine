/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_color.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:47:07 by seojo             #+#    #+#             */
/*   Updated: 2023/02/12 20:12:34 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_FILE_COLOR_H
# define CHECK_MAP_FILE_COLOR_H

# include "ft_open.h"
# include "check_map_color_line.h"
# include "world.h"

char	*split_filename(char *line);
char	*check_path(char *read_line);
char	*split_color(char *read_line, int *color);
int		check_color(char *read_line);

#endif
