#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_data
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}				t_data;

typedef struct	s_info
{
	int	w;
	int	h;
	char bg;
}				t_info;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	dp_free(char **ptr, int size)
{
	while (--size >= 0)
		free(ptr[size]);
	free(ptr);
}

int	init_map(char **map, t_info i)
{
	int	y;
	int	x;

	y = -1;
	while (++y < i.h)
	{
		map[y] = malloc(sizeof(char) * i.w);
		if (!map)
		{
			dp_free(map, y);
			return (1);
		}
		x = -1;
		while (++x < i.w)
			map[y][x] = i.bg;
	}
	return (0);
}

int	in_data(t_data d, int y, int x)
{
	return (d.x <= x && x <= d.x + d.w && d.y <= y && y <= d.y + d.h);
}

int	in_edge(t_data d, int y ,int x)
{
	return (x < d.x + 1 || d.x + d.w - 1 < x || y < d.y || d.y + d.h - 1 < y);
}

void	draw_map(char **map, t_info i, t_data d)
{
	int	y;
	int	x;

	y = -1;
	while (++y < i.h)
	{
		while (++x < i.w)
		{
			if (d.type == 'R' && in_data(d, y, x))
				map[y][x] = d.c;
			else if (d.type == 'r' && in_data(d, y, x) && in_edge(d, y, x))
				map[y][x] = d.c;
		}
	}
}

void	print_map(char **map, t_info i)
{
	int	y;
	int	x;

	y = -1;
	while (++y < i.h)
	{
		x = -1;
		while (++x < i.w)
			write(1, &map[y][x], 1);
		write(1, "\n", 1);
	}
}

int micro_paint(FILE *f)
{
	t_info	i;
	t_data	d;
	char	**map;
	int		ret;

	if (fscanf(f, "%d %d %c\n", &i.w, &i.h, &i.bg) != 3)
		return (1);
	if (i.w <=0 || i.w > 300 || i.h <= 0 || i.h > 300)
		return (1);
	map = malloc(sizeof(char *) * i.h);
	if (!map || init_map(map, i))
		return (2);
	ret = fscanf(f, "%c %f %f %f %f %c\n", &d.type, &d.x, &d.y, &d.w, &d.h, &d.c);
	while (ret == 6)
	{
		if (d.w <= 0 || d.h  <= 0 || (d.type != 'r' && d.type !='R'))
		{
			dp_free(map, i.h);
			return (1);
		}
		draw_map(map, i, d);
		ret = fscanf(f, "%c %f %f %f %f %c\n", &d.type, &d.x, &d.y, &d.w, &d.h, &d.c);
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

int main(int ac, char **av)
{
	FILE *f;
	int		rtn;

	if (ac != 2)
		ft_putstr("Error: argument\n");
	f = fopen(av[1], "r");
	if (!f)
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	rtn = micro_paint(f);
	if (rtn)
	{
		if (rtn == 1)
			ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	return (0);
}
