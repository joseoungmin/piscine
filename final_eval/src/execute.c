/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:13:52 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 19:25:25 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	ft_execve(char *path, char **cmd)
{
	if (execve(path, cmd, NULL) == -1)
	{
		if (errno == 13)
			error_cmd(cmd[0], strerror(is_direc(path, cmd[0], errno)), 126);
		if (ft_strchr(path, '/'))
			error_cmd(cmd[0], strerror(is_direc(path, cmd[0], errno)), 127);
		error_cmd(cmd[0], "command not found", 127);
	}
}

static void	check_gdshell(t_env_lst *lst, t_cmd_unit *unit, \
		int stdfd[2], int *exit_stat)
{
	ft_close(stdfd[0]);
	if (dup_redirection(unit, stdfd[1], exit_stat))
		exit(*exit_stat);
	ft_close(stdfd[1]);
	if (ft_strncmp(unit->cmd[0], "./minishell", 12) == 0)
		gd_shell(lst, 0);
	sig_handler(DEFAULT, DEFAULT);
}

static void	execute_cmd(t_env_lst *lst, t_cmd_unit *unit, \
		int stdfd[2], int *exit_stat)
{
	const t_env_node	*home_node = find_node(lst, "HOME");
	const t_env_node	*node = find_node(lst, "PATH");
	const char			*check_slash = ft_strchr(unit->cmd[0], '/');
	char				**paths;
	char				*path;

	check_gdshell(lst, unit, stdfd, exit_stat);
	if (check_built_in(unit->cmd[0]))
		play_built_in(lst, unit->cmd, 1, exit_stat);
	if (node == NULL || check_slash != NULL)
	{
		if (ft_strncmp(unit->cmd[0], "~", 1) == 0)
			path = ft_strjoin(home_node->value, (unit->cmd[0] + 1));
		else
			path = unit->cmd[0];
		ft_execve(path, unit->cmd);
	}
	else
	{
		path = node->value;
		paths = ft_split(path, ':');
		if (paths != NULL)
			path = parse_command(unit->cmd[0], paths);
		ft_execve(path, unit->cmd);
	}
}

int	ft_wait(pid_t pid)
{
	int	stat;

	waitpid(pid, &stat, 0);
	while (wait(0) != -1)
		continue ;
	if (0 == (stat & 0xff))
		return (stat >> 8);
	return (stat);
}

void	execute_process(t_env_lst *lst, t_cmd_unit *cmd_unit, \
		int oldfd[2], int *exit_stat)
{
	t_cmd_unit	*unit;
	t_cmd_unit	*del_unit;
	int			fd[2];
	pid_t		pid;

	unit = cmd_unit;
	while (unit)
	{
		ft_pipe(fd);
		pid = ft_fork();
		if (pid == 0)
		{
			ft_close(fd[READ]);
			ft_dup2(fd[WRITE], STDOUT_FILENO);
			ft_close(fd[WRITE]);
			execute_cmd(lst, unit, oldfd, exit_stat);
		}
		ft_close(fd[WRITE]);
		ft_dup2(fd[READ], STDIN_FILENO);
		ft_close(fd[READ]);
		del_unit = unit;
		unit = unit->next;
		del_one_unit(del_unit);
	}
	*exit_stat = ft_wait(pid);
}
