/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:03:16 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:03:22 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec		t_vec;
typedef struct s_ivec		t_ivec;

struct s_vec
{
	double	x;
	double	y;
};

struct s_ivec
{
	int	x;
	int	y;
};

#endif
