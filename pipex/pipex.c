/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:03:40 by seojo             #+#    #+#             */
/*   Updated: 2022/09/12 13:26:26 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

///모든 인자를 받는 명령어는 ' " 처리를 해야한다..
///makefile arch 처리구문 

void	first_exec(t_node *node, int fd[2])
{
	char	**cmd;
	int		in_fd;

	in_fd = open(node->av[1], O_RDONLY);
	if (in_fd == -1)
		ft_perror(node->av[1]);
	if (node->path == NULL)
		ft_msg_error(node->av[2], "command not found", 127);
	if (dup2(in_fd, 0) == -1)
		ft_perror(NULL);
	if (dup2(fd[1], 1) == -1)
		ft_perror(NULL);
	close(in_fd);
	fd_close(fd[0], fd[1]);
	cmd = msplit(node->av[2], ' ');
	if (execve(node->path, cmd, node->envp) == -1)
		ft_perror(NULL);
}

void	last_exec(t_node *node, int fd[2])
{
	char	**cmd;
	int		out_fd;

	out_fd = open(node->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
		ft_perror(node->av[4]);
	if (node->path2 == NULL)
		ft_msg_error(node->av[3], "command not found", 127);
	if (dup2(out_fd, 1) == -1)
		ft_perror(NULL);
	if (dup2(fd[0], 0) == -1)
		ft_perror(NULL);
	close(out_fd);
	fd_close(fd[0], fd[1]);
	cmd = msplit(node->av[3], ' ');
	if (execve(node->path2, cmd, node->envp) == -1)
		ft_perror(NULL);
}

int	ft_fork(t_node *node)
{
	int		fd[2];
	pid_t	pid;
	int		stat;
	int		i;

	if (pipe(fd) == -1)
		ft_perror("ERROR of pipe");
	i = -1;
	while (++i < node->ac - 3)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				first_exec(node, fd);
			else
				last_exec(node, fd);
		}
	}
	fd_close(fd[0], fd[1]);
	waitpid(pid, &stat, 0);
	free_node(node);
	if (0 == (stat & 0xff))
		return (stat >> 8);
	return (stat);
}

int	main(int ac, char **av, char **envp)
{
	t_node	*node;

	if (ac != 5)
		ft_msg_error("Arg", "wrong count of arguments", 1);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_msg_error("malloc", "malloc fail", 1);
	node_init(ac, av, envp, node);
	return (ft_fork(node));
}
