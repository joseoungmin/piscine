/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:03:40 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 15:53:08 by seojo            ###   ########.fr       */
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
	int		stat;
	pid_t	pid;

	ft_dup2(node->out_fd, 1);
	ft_close(node->out_fd);
	pid = fork();
	if (pid == 0)
		ft_exec(node, idx);
	ft_close(0);
	waitpid(pid, &stat, 0);
	while (wait(NULL) != -1)
		continue ;
	if (0 == (stat & 0xff))
		return (stat >> 8);
	return (stat);
}

int	make_child(t_node *node, int i)
{
	pid_t	pid;

	while (++i < node->ac - 4)
	{
		ft_pipe(node->fd);
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
	return (last_exec(node, i));
}

int	main(int ac, char **av, char **envp)
{
	t_node	node;

	if (ac < 5)
		ft_msg_error("Arg", "wrong count of arguments", 1);
	node_init(ac, av, envp, &node);
	return (make_child(&node, node.hd - 1));
}
