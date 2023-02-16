/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:20:09 by seojo             #+#    #+#             */
/*   Updated: 2023/02/16 18:20:13 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMLX_H
# define TMLX_H

typedef struct s_mlx		t_mlx;
typedef struct s_image		t_image;

struct s_image
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
};

struct s_mlx
{
	t_image	timg_main;
	t_image	timg_wall_tex[4];
	void	*mlx;
	void	*win;
};

#endif
