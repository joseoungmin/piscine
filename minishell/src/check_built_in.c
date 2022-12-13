/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:14:22 by seojo             #+#    #+#             */
/*   Updated: 2022/12/08 15:45:27 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static char	*rt_lower_cmd(char *cmd)
{
	char	*rt_cmd;
	int		i;

	rt_cmd = ft_calloc(ft_strlen(cmd) + 1, sizeof(char));
	if (!rt_cmd)
		error_cmd("malloc", strerror(12), 1);
	i = -1;
	while (cmd[++i])
		rt_cmd[i] = ft_tolower(cmd[i]);
	rt_cmd[i] = '\0';
	return (rt_cmd);
}

static int	ft_free_return(char *cmd)
{
	ft_free(cmd);
	return (1);
}

int	check_built_in(char *cmd)
{
	int			i;
	const int	cmd_len = ft_strlen(cmd) + 1;
	char		*cmd_cpy;
	const char	arr[7][7] = {
		"cd", "env", "pwd", "echo", "export", "unset", "exit"
	};

	cmd_cpy = rt_lower_cmd(cmd);
	i = -1;
	while (++i < 7)
	{
		if (i > 3)
		{
			if (ft_strncmp(cmd, arr[i], cmd_len) == 0)
				return (ft_free_return(cmd_cpy));
		}
		else if (ft_strncmp(cmd_cpy, arr[i], cmd_len) == 0)
			return (ft_free_return(cmd_cpy));
	}
	ft_free(cmd_cpy);
	return (0);
}

void	play_built_in(t_env_lst *lst, char **cmd, int type, int *exit_stat)
{
	char	*cmd_cpy;

	cmd_cpy = rt_lower_cmd(cmd[0]);
	if (!cmd_cpy)
		*exit_stat = error_cmd("checkcmd", strerror(12), 0);
	else if (!ft_strncmp(cmd_cpy, "cd", 3))
		*exit_stat = ft_cd(lst, cmd);
	else if (!ft_strncmp(cmd_cpy, "env", 4))
		*exit_stat = ft_env(lst);
	else if (!ft_strncmp(cmd_cpy, "pwd", 4))
		*exit_stat = ft_pwd();
	else if (!ft_strncmp(cmd_cpy, "echo", 5))
		*exit_stat = ft_echo(cmd);
	else if (!ft_strncmp(cmd[0], "export", 7))
		*exit_stat = ft_export(lst, cmd);
	else if (!ft_strncmp(cmd[0], "unset", 6))
		*exit_stat = ft_unset(lst, cmd);
	else if (!ft_strncmp(cmd[0], "exit", 5))
		*exit_stat = ft_exit(cmd);
	else
		return ;
	if (type == 1)
		exit(*exit_stat);
	ft_free(cmd_cpy);
}
