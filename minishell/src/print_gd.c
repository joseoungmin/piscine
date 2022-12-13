/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:43:46 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 19:38:08 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_gd.h"

static void	m_sleep(void)
{
	long long	i;
	long long	cnt;
	long long	j;
	long long	j_cnt;

	i = 0;
	cnt = 0;
	while (i++ && cnt < LLONG_MAX)
	{
		j = 0;
		j_cnt = 0;
		while (j++ && j_cnt < LLONG_MAX)
		{
			if (j == LLONG_MAX)
			{
				j_cnt++;
				j = 0;
			}
		}
		if (i == LLONG_MAX)
		{
			cnt++;
			i = 0;
		}
	}
}

static void	ms_sleep(long long time)
{
	time *= 519000;
	while (time--)
		m_sleep();
}

static void	print_line(char	*line, int fd)
{
	int	i;
	int	j;

	i = 100;
	while (line)
	{
		j = 0;
		while (line[j])
		{
			write(1, &line[j++], 1);
			ms_sleep(10000 / i);
			i += 18;
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	print_gd(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("src/gd.txt", O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (!line)
	{
		printf("gnl_error\n");
		close(fd);
		return ;
	}
	i = 0;
	while (i++ < 100)
		write(1, "\n", 1);
	print_line(line, fd);
	close(fd);
}
