/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:55 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 23:29:22 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"


# include <stdio.h>
int key_press(int keycode, t_player *player)
{
    if (keycode == KEY_A)
        player->x--;
    if (keycode == KEY_D)
        player->x++;
    if (keycode == KEY_W)
        player->y--;
    if (keycode == KEY_S)
        player->y++;
    printf("x:y = %f:%f\n", player->x, player->y);
    if (keycode == KEY_ESC)
        exit(0);
    
    return (0);
}