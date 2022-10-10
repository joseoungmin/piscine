/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:27:05 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/10/06 17:27:12 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_info
{
	int		w;
	int		h;
	char	bg;
}	t_info;

typedef struct s_data
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}	t_data;

#endif
