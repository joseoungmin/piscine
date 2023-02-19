/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:38:17 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 12:49:56 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_FILE_H
# define CHECK_MAP_FILE_H

# include "ft_open.h"
# include "world.h"
# include "libft.h"
# include "check_map_color_line.h"

char	*split_filename(char *line);
char	*check_path(char *read_line);
char	*check_texture_file(t_world *world, char *read_line, int rot);

#endif
