/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_func_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:31:23 by seojo             #+#    #+#             */
/*   Updated: 2022/09/15 07:50:20 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_msg_error(char *str, char *msg, int exit_code)
{
	write(2, "pipex: ", 7);
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(exit_code);
}

void	ft_perror(char *str)
{
	write(2, "pipex: ", 7);
	perror(str);
	exit(1);
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
