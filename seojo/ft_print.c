/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:11:49 by seojo             #+#    #+#             */
/*   Updated: 2022/11/05 14:40:12 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_gd(void)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open("gd.txt", O_RDONLY);
	line = get_next_line(fd);
//	if (!line)
//		ft_error("gnl error");
	while (i++ < 100)
		write(1, "\n", 1);
	while (line)
	{
		printf("%s", line);
		ms_sleep(10000 / i);
		i += 60;
		free(line);
		line = get_next_line(fd);
	}
	j = 0;
	while (j++ < 5)
	{
		write(1, "\n", 1);
		ms_sleep(10000 / i);
		i += 60;
	}
}
