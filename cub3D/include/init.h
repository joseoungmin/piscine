/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:40:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/28 16:21:55 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include <stdlib.h>
# include "map.h"
# include "error.h"
# include "mlx.h"

t_map	*init_map(void);
void	init_world(t_map *map);

#endif
