/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:47:23 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 17:52:26 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_map_err	t_map_err;
typedef struct s_map	t_map;

enum e_map_err
{
	FALSE = 0,
	TRUE = 1,
	RED = 0,
	GREEN = 1,
	BLUE = 2,
};

struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		ceiling;
	char	**map;
	int		width;
	int		height;
	char	direction;
};

#endif
