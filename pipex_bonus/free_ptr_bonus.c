/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:31:23 by seojo             #+#    #+#             */
/*   Updated: 2022/09/13 18:02:05 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_single_ptr(char *str)
{
	free(str);
	str = NULL;
}

void	free_double_ptr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	free_node(t_node *node)
{
	free(node->path);
	node->path = NULL;
	free(node);
	node = NULL;
}

void	fd_close_all(t_fd **fd_set, int last)
{
	int	i;

	i = -1;
	while (++i < last)
	{
		close(fd_set[i]->fd[0]);
		close(fd_set[i]->fd[1]);
	}
}

void	fd_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
