/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:29:48 by seojo             #+#    #+#             */
/*   Updated: 2023/02/08 18:38:34 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef draw_mini_ray_H
# define draw_mini_ray_H

# include <float.h>
# include "mini_ray.h"

# define COL_RED 0xFF0000
# define RAY_RANGE (M_PI / 3.0)
# define RAY_COUTNT 121

void	draw_mini_ray(t_map *map);

#endif
