/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:03:40 by seojo             #+#    #+#             */
/*   Updated: 2022/09/15 09:02:22 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_heredoc(t_node *node)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		if (!ft_strncmp(tmp, node->av[2], ft_strlen(node->av[2])))
		{
			if (tmp[ft_strlen(node->av[2])] == '\n')
			{
				free(tmp);
				break ;
			}
		}
		write(node->in_fd, tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(0);
	}
	close(node->in_fd);
	node->in_fd = open(".heredoc.tmp", O_RDONLY, 0644);
}

static void	ft_exec(t_node *node, int idx)
{
	char	**cmd;
	char	*path;

	path = find_path(node->envp, node->av[idx + 2], -1);
	cmd = msplit(node->av[idx + 2], ' ');
	if (execve(path, cmd, node->envp) == -1)
	{
		if (errno == 13)
			ft_msg_error(cmd[0], "permission denied", 126);
		ft_msg_error(node->av[idx + 2], "command not found", 127);
	}
}

static int	last_exec(t_node *node, int idx)
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
	if (node->hd == 1)
		unlink(".heredoc.tmp");
	if (0 == (stat & 0xff))
		return (stat >> 8);
	return (stat);
}

static int	make_child(t_node *node, int i, int last)
{
	pid_t	pid;

	while (++i < last)
	{
		ft_pipe(node->fd);
		pid = fork();
		if (pid == 0)
		{
			if (i == 0 && node->in_fd == -1)
				exit (1);
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
	init_and_open(ac, av, envp, &node);
	return (make_child(&node, node.hd - 1, ac - 4));
}
