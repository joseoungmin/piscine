/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:25:17 by seojo             #+#    #+#             */
/*   Updated: 2022/12/03 16:42:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
		error_cmd("close", strerror(errno), 1);
}

void	ft_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		error_cmd("pipe", strerror(errno), 1);
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_cmd("fork", strerror(errno), 1);
	return (pid);
}

void	ft_dup2(int fd1, int fd2)
{
	if (fd1 == fd2)
		return ;
	if (dup2(fd1, fd2) == -1)
		error_cmd("dup2", strerror(errno), 1);
}
