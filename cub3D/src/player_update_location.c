/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update_location.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:09:42 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 23:14:10 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "player_update_location.h"

void    p_location_update(t_map *map)
{
    if (map->player->move_forward)
    {
        if (map->world_map[(int)(map->player->pos_x + map->player->dir_x * map->player->move_speed)][(int)(map->player->pos_y)] == 0)
            map->player->pos_x += map->player->dir_x * map->player->move_speed;
        if (map->world_map[(int)(map->player->pos_x)][(int)(map->player->pos_y + map->player->dir_y * map->player->move_speed)] == 0)
            map->player->pos_y += map->player->dir_y * map->player->move_speed;
    }
    if (map->player->move_back)
    {
        if (map->world_map[(int)(map->player->pos_x - map->player->dir_x * map->player->move_speed)][(int)(map->player->pos_y)] == 0)
            map->player->pos_x -= map->player->dir_x * map->player->move_speed;
        if (map->world_map[(int)(map->player->pos_x)][(int)(map->player->pos_y - map->player->dir_y * map->player->move_speed)] == 0)
            map->player->pos_y -= map->player->dir_y * map->player->move_speed;
    }
    if (map->player->move_left)
    {
        if (map->world_map[(int)(map->player->pos_x - map->player->plane_x * map->player->move_speed)][(int)(map->player->pos_y)] == 0)
            map->player->pos_x -= map->player->plane_x * map->player->move_speed;
        if (map->world_map[(int)(map->player->pos_x)][(int)(map->player->pos_y - map->player->plane_y * map->player->move_speed)] == 0)
            map->player->pos_y -= map->player->plane_y * map->player->move_speed;
    }
    if (map->player->move_right)
    {
        if (map->world_map[(int)(map->player->pos_x + map->player->plane_x * map->player->move_speed)][(int)(map->player->pos_y)] == 0)
            map->player->pos_x += map->player->plane_x * map->player->move_speed;
        if (map->world_map[(int)(map->player->pos_x)][(int)(map->player->pos_y + map->player->plane_y * map->player->move_speed)] == 0)
            map->player->pos_y += map->player->plane_y * map->player->move_speed;
    }
}

void    p_rotation_update(t_map *map)
{
    double  old_dir_x;
    double  old_plane_x;

    if (map->player->rot_left)
    {
        old_dir_x = map->player->dir_x;
        map->player->dir_x = map->player->dir_x * cos(map->player->rot_speed) - map->player->dir_y * sin(map->player->rot_speed);
        map->player->dir_y = old_dir_x * sin(map->player->rot_speed) + map->player->dir_y * cos(map->player->rot_speed);
        old_plane_x = map->player->plane_x;
        map->player->plane_x = map->player->plane_x * cos(map->player->rot_speed) - map->player->plane_y * sin(map->player->rot_speed);
        map->player->plane_y = old_plane_x * sin(map->player->rot_speed) + map->player->plane_y * cos(map->player->rot_speed);
    }
    if (map->player->rot_right)
    {
        old_dir_x = map->player->dir_x;
        map->player->dir_x = map->player->dir_x * cos(-map->player->rot_speed) - map->player->dir_y * sin(-map->player->rot_speed);
        map->player->dir_y = old_dir_x * sin(-map->player->rot_speed) + map->player->dir_y * cos(-map->player->rot_speed);
        old_plane_x = map->player->plane_x;
        map->player->plane_x = map->player->plane_x * cos(-map->player->rot_speed) - map->player->plane_y * sin(-map->player->rot_speed);
        map->player->plane_y = old_plane_x * sin(-map->player->rot_speed) + map->player->plane_y * cos(-map->player->rot_speed);
    }
}

void    p_update(t_map *map)
{
    p_location_update(map);
    p_rotation_update(map);
}