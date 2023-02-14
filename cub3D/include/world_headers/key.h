/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:42:07 by seojo             #+#    #+#             */
/*   Updated: 2023/02/12 19:02:08 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

typedef enum e_keycode	t_keycode;

enum e_event
{
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_DESTROY_NOTIFY = 17,
};

enum e_keycode
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_M = 46,
	KEY_O = 31,
	KEY_TAB = 48,
	KEY_ESC = 53,
	KEY_ARROW_L = 123,
	KEY_ARROW_R = 124,
	KEY_NONE = -1
};

#endif
