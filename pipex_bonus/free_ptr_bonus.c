/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:31:23 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 13:14:41 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_sptr(char *str)
{
	free(str);
	str = NULL;
}

void	free_dptr(char **str)
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

void	ft_close(int fd)
{
	if (close(fd) == -1)
		ft_perror("close_error");
}

void	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		ft_perror("dup2_error");
}

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
		ft_perror("pipe_error");
}
