/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:07:51 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:08:26 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_SET_H
# define ENUM_SET_H

typedef enum e_card			t_card;
typedef enum e_color		t_color;

enum e_color
{
	RED,
	GREEN,
	BLUE,
};

enum e_card
{
	WE,
	EA,
	NO,
	SO
};

#endif
