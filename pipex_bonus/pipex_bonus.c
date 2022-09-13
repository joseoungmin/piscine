/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:03:40 by seojo             #+#    #+#             */
/*   Updated: 2022/09/13 22:00:04 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

///makefile arch 처리구문 

void	ft_exec(t_node *node, int idx)
{
	char	**cmd;

	node->path = find_path(node->envp, node->av[idx + 2], -1);
	if (node->path == NULL)
		ft_msg_error(node->av[idx + 2], "command not found", 127);
	cmd = msplit(node->av[idx + 2], ' ');
	if (execve(node->path, cmd, node->envp) == -1)
		ft_perror("execve-2");
}

int	last_exec(t_node *node, int out_fd, int idx)
{
	char	**cmd;
	int		pid;
	int		stat;

	if (dup2(out_fd, 1) == -1)
		ft_perror("last_exec");
	close(out_fd);
	pid = fork();
	if (pid == 0)
	{
		node->path = find_path(node->envp, node->av[idx + 2], -1);
		if (node->path == NULL)
			ft_msg_error(node->av[idx + 2], "command not found", 127);
		cmd = msplit(node->av[idx + 2], ' ');
		if (execve(node->path, cmd, node->envp) == -1)
			ft_perror("execve-3");
	}
	waitpid(pid, &stat, 0);
	if (0 == (stat & 0xff))
		return (stat >> 8);
	return (stat);
}

int	ft_fork(t_node *node, int i)
{
	int		stat;
	int		in_fd;
	int		out_fd;
	int 	fd[2];
	pid_t	pid;

	in_fd = open(node->av[1], O_RDONLY);
	if (in_fd == -1)
		ft_perror(node->av[1]);
	//에러 진행

	out_fd = open(node->av[node->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
		ft_perror(node->av[node->ac - 1]);
	//에러 종료

	if (dup2(in_fd, 0) == -1)
		ft_perror("ft_fork_dup2");
	close(in_fd);

	i = -1;
	while (++i < node->ac - 4)
	{
		if (pipe(fd) == -1)
			ft_perror("ERROR of pipe");
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			if (dup2(fd[1], 1) == -1)
				ft_perror("ft_fork_in_dup2-1");
			close(fd[1]);
			ft_exec(node, i);
		}
		close(fd[1]);
		if (dup2(fd[0], 0) == -1)
			ft_perror("ft_fork_in_dup2-1");
		close(fd[0]);
	}
	stat = last_exec(node, out_fd, i);
	free_node(node);
	while (wait(NULL) != -1)
		continue ;
	return (stat);
}

int	main(int ac, char **av, char **envp)
{
	t_node	*node;

	if (ac < 5)
		ft_msg_error("Arg", "wrong count of arguments", 1);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_msg_error("malloc", "malloc fail", 1);
	node_init(ac, av, envp, node);
	return (ft_fork(node, -1));
}
