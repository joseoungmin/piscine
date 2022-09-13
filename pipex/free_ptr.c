/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:31:23 by seojo             #+#    #+#             */
/*   Updated: 2022/09/12 16:44:04 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	free(node->path2);
	node->path = NULL;
	free(node);
	node = NULL;
}

void	fd_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
