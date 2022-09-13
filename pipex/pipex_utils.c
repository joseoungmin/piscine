/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:37:46 by seojo             #+#    #+#             */
/*   Updated: 2022/09/12 03:30:40 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **envp, char *cmd, char *buf[2], int i)
{
	char	**find_str;
	char	**cmd_buf;

	cmd_buf = ft_split(cmd, ' ');
	if (access(cmd_buf[0], X_OK) == 0)
		return (cmd_buf[0]);
	while (ft_strncmp("PATH=", envp[++i], 5) != 0)
		;
	find_str = ft_split(envp[i] + 5, ':');
	i = -1;
	while (find_str[++i])
	{
		buf[0] = ft_strjoin(find_str[i], "/");
		buf[1] = ft_strjoin(buf[0], cmd_buf[0]);
		free_single_ptr(buf[0]);
		if (access(buf[1], X_OK) == 0)
		{
			free_double_ptr(find_str);
			free_double_ptr(cmd_buf);
			return (buf[1]);
		}
		free_single_ptr(buf[1]);
	}
	return (NULL);
}

void	node_init(int ac, char **av, char **envp, t_node *node)
{
	char	*buf[2];

	node->ac = ac;
	node->av = av;
	node->envp = envp;
	node->path = find_path(envp, av[2], buf, -1);
	node->path2 = find_path(envp, av[3], buf, -1);
}

void	ft_perror(char *str)
{
	write(2, "pipex: ", 7);
	perror(str);
	exit(1);
}

void	ft_msg_error(char *str, char *msg, int exit_code)
{
	write(2, "pipex: ", 7);
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(exit_code);
}
