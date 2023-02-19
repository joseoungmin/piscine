/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_color.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:33:53 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 13:03:34 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_COLOR_H
# define CHECK_MAP_COLOR_H

# include "libft.h"
# include "world.h"
# include "check_map_color_line.h"

enum
{
	F = 1,
	C = 2,
};

char	*split_color(char *read_line, int *color);
int		check_color(char *read_line);
int		check_color_argu(t_world *world, char *read_line, int fc);

#endif
