/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:54:15 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/10/06 17:26:26 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	dp_free(char **ptr, int size)
{
	while (--size >= 0)
		free(ptr[size]);
	free(ptr);
}

int	in_data(t_data data, int x, int y)
{
	return (sqrtf(powf(data.x - x, 2) + powf(data.y - y, 2)) <= data.r);
}

int	in_edge(t_data data, int x, int y)
{
	return (sqrtf(powf(data.x - x, 2) + powf(data.y - y, 2)) > data.r - 1);
}

void	draw_map(char **map, t_info info, t_data data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info.h)
	{
		x = -1;
		while (++x < info.w)
		{
			if (data.type == 'C' && in_data(data, x, y))
				map[y][x] = data.c;
			else if (data.type == 'c' && \
					in_data(data, x, y) && in_edge(data, x, y))
				map[y][x] = data.c;
		}
	}
}

void	print_map(char **map, t_info info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info.h)
	{
		x = -1;
		while (++x < info.w)
			write(1, &map[y][x], 1);
		write(1, "\n", 1);
	}
}

int	init_map(char **map, t_info info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info.h)
	{
		map[y] = (char *)malloc(sizeof(char) * info.w);
		if (map[y] == NULL)
		{
			dp_free(map, y);
			return (1);
		}
		x = -1;
		while (++x < info.w)
			map[y][x] = info.bg;
	}
	return (0);
}

int	mini_paint(FILE *f)
{
	t_info	i;
	t_data	d;
	char	**map;
	int		ret;

	if (fscanf(f, "%d %d %c\n", &i.w, &i.h, &i.bg) != 3)
		return (1);
	if (i.w <= 0 || i.w > 300 || i.h <= 0 || i.h > 300)
		return (1);
	map = (char **)malloc(sizeof(char *) * i.h);
	if (map == NULL || init_map(map, i))
		return (2);
	ret = fscanf(f, "%c %f %f %f %c\n", &d.type, &d.x, &d.y, &d.r, &d.c);
	while (ret == 5)
	{
		if (d.r <= 0 || (d.type != 'c' && d.type != 'C'))
		{
			dp_free(map, i.h);
			return (1);
		}
		draw_map(map, i, d);
		ret = fscanf(f, "%c %f %f %f %c\n", &d.type, &d.x, &d.y, &d.r, &d.c);
	}
	if (ret != EOF)
	{
		dp_free(map, i.h);
		return (1);
	}
	print_map(map, i);
	dp_free(map, i.h);
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	ret = mini_paint(file);
	if (ret)
	{
		if (ret == 1)
			ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	return (0);
}
