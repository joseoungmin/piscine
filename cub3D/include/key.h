/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:42:07 by seojo             #+#    #+#             */
/*   Updated: 2023/01/27 19:26:20 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H
# define X_KEY_PRESS	2
# define X_KEY_RELEASE	3
# define X_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124

typedef struct s_key    t_key;

struct s_key
{
    int w;
    int a;
    int s;
    int d;
    int left;
    int right;
};

#endif
