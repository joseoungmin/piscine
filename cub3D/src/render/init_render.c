/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:49:14 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 17:29:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_render.h"

int	*load_image(t_mlx *tmlx, t_image *img, char *path)
{
	int	*res;
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(tmlx->mlx, path, &img->w, &img->h);
	if (!img->img)
		err_exit("image load error");
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
	&img->line_len, &img->endian);
	res = malloc(sizeof(int) * img->w * img->h);
	if (res == NULL)
		err_exit("malloc error");
	y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{
			res[y * img->w + x] = img->data[y * img->w + x];
			x++;
		}
		y++;
	}
	return (res);
}

void	texture_load(t_world *world)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (world->tex_path[i])
			world->wall_tex[i] = load_image(world->tmlx, \
			&world->tmlx->timg_wall_tex[i], world->tex_path[i]);
		i++;
	}
}

void	set_player_cardinal(t_player *p)
{
	double	degree;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	degree = 0;
	if (p->cardinal == 'N')
		return ;
	else if (p->cardinal == 'W')
		degree = M_PI / 2;
	else if (p->cardinal == 'S')
		degree = M_PI;
	else if (p->cardinal == 'E')
		degree = M_PI * 3 / 2;
	p->dir.x = p->dir.x * cos(-degree) - p->dir.y * sin(-degree);
	p->dir.y = old_dir_x * sin(-degree) + p->dir.y * cos(-degree);
	p->plane.x = p->plane.x * cos(-degree) - p->plane.y * sin(-degree);
	p->plane.y = old_plane_x * sin(-degree) + p->plane.y * cos(-degree);
	return ;
}

void	create_screen_buf(t_world *world)
{
	int	i;

	world->screen_buf = malloc(sizeof(int *) \
	* world->screen_h);
	i = 0;
	while (i < world->screen_h)
	{
		world->screen_buf[i] = malloc(sizeof(int) \
		* world->screen_w);
		ft_memset(world->screen_buf[i], 0, sizeof(int) \
		* world->screen_w);
		i++;
	}
}

void	init_render(t_world *world)
{
	world->tmlx = init_mlx();
	create_screen_buf(world);
	texture_load(world);
	set_player_cardinal(&world->player);
}
