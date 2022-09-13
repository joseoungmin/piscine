/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:03:40 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 02:20:22 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exec(t_node *node, int idx)
{
	char	**cmd;
	char	*path;

	path = find_path(node->envp, node->av[idx + 2], -1);
	if (path == NULL)
		ft_msg_error(node->av[idx + 2], "command not found", 127);
	cmd = msplit(node->av[idx + 2], ' ');
	if (execve(path, cmd, node->envp) == -1)
		ft_perror("execve-2");
}

int	last_exec(t_node *node, int idx)
{
	char	**cmd;
	char	*path;
	int		pid;
	int		stat;

	ft_dup2(node->out_fd, 1);
	ft_close(node->out_fd);
	pid = fork();
	if (pid == 0)
	{
		path = find_path(node->envp, node->av[idx + 2], -1);
		if (path == NULL)
			ft_msg_error(node->av[idx + 2], "command not found", 127);
		cmd = msplit(node->av[idx + 2], ' ');
		if (execve(path, cmd, node->envp) == -1)
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
	pid_t	pid;

	while (++i < node->ac - 4)
	{
		if (pipe(node->fd) == -1)
			ft_perror("ERROR of pipe");
		pid = fork();
		if (pid == 0)
		{
			if (i == 0 && node->in_fd == -1)
				ft_msg_error(node->av[1 + node->hd], \
						"no such file or directory", 1);
			ft_close(node->fd[0]);
			ft_dup2(node->fd[1], 1);
			ft_close(node->fd[1]);
			ft_exec(node, i);
		}
		ft_close(node->fd[1]);
		ft_dup2(node->fd[0], 0);
		ft_close(node->fd[0]);
	}
	stat = last_exec(node, i);
	while (wait(NULL) != -1)
		continue ;
	return (stat);
}

int	main(int ac, char **av, char **envp)
{
	t_node	node;

	if (ac < 5)
		ft_msg_error("Arg", "wrong count of arguments", 1);
	node_init(ac, av, envp, &node);
	return (ft_fork(&node, -1));
}
