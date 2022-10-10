/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:27:16 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/10/06 17:27:29 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

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
	float	r;
	char	c;
}	t_data;

#endif
