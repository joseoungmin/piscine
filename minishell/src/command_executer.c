/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:35:09 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 19:05:21 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	is_direc(char *path, char *cmd, int tmp_errno)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		closedir(dir);
		error_cmd(cmd, "is a directory", 126);
	}
	return (tmp_errno);
}

char	*ft_path_join(char *paths, char *cmd)
{
	const int	cmd_len = ft_strlen(cmd);
	const int	paths_len = ft_strlen(paths);
	char		*rt_path;

	rt_path = malloc(sizeof(char) * (cmd_len + paths_len + 2));
	if (rt_path == NULL)
		error_cmd("malloc", strerror(12), 1);
	ft_memcpy(rt_path, paths, paths_len);
	ft_memcpy(rt_path + paths_len, "/", 1);
	ft_memcpy(rt_path + paths_len + 1, cmd, cmd_len);
	rt_path[cmd_len + paths_len + 1] = '\0';
	return (rt_path);
}

char	*parse_command(char *cmd, char **paths)
{
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_path_join(paths[i], cmd);
		if (!ft_access(path, XOK))
			return (path);
		free(path);
		i++;
	}
	error_cmd(cmd, "command not found", 127);
	return (cmd);
}

static void	old_fd_change(int stdfd[2])
{
	ft_dup2(stdfd[0], STDIN_FILENO);
	ft_dup2(stdfd[1], STDOUT_FILENO);
	ft_close(stdfd[0]);
	ft_close(stdfd[1]);
}

void	command_executer(t_env_lst *lst, t_cmd_unit *unit, int *exit_stat)
{
	int	oldfd[2];

	if (unit == NULL || unit->cmd[0] == NULL)
	{
		exit_stat = 0;
		return ;
	}
	oldfd[0] = dup(STDIN_FILENO);
	oldfd[1] = dup(STDOUT_FILENO);
	if (unit->next == NULL)
	{
		if (check_built_in(unit->cmd[0]))
		{
			if (dup_redirection(unit, oldfd[1], exit_stat))
				return ;
			play_built_in(lst, unit->cmd, 0, exit_stat);
			del_one_unit(unit);
			old_fd_change(oldfd);
			return ;
		}
	}
	sig_handler(IGNORE, IGNORE);
	execute_process(lst, unit, oldfd, exit_stat);
	sig_handler(GDSET, GDSET);
	old_fd_change(oldfd);
}
