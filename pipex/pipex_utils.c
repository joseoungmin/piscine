/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:37:46 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 01:58:46 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_join_slash(char *src, char *dest)
{
	char	*buf[2];

	buf[0] = ft_strjoin(src, "/");
	buf[1] = ft_strjoin(buf[0], dest);
	free_single_ptr(buf[0]);
	return (buf[1]);
}

static char	*find_path(char **envp, char *cmd, int i)
{
	char	**find_str;
	char	**cmd_buf;
	char	*buf;

	cmd_buf = ft_split(cmd, ' ');
	if (access(cmd_buf[0], X_OK) == 0)
		return (cmd_buf[0]);
	while (ft_strncmp("PATH=", envp[++i], 5) != 0)
		continue ;
	find_str = ft_split(envp[i] + 5, ':');
	i = -1;
	while (find_str[++i])
	{
		buf = ft_join_slash(find_str[i], cmd_buf[0]);
		if (access(buf, X_OK) == 0)
		{
			free_double_ptr(find_str);
			free_double_ptr(cmd_buf);
			return (buf);
		}
		free_single_ptr(buf);
	}
	free_double_ptr(find_str);
	free_double_ptr(cmd_buf);
	return (NULL);
}

void	node_init(int ac, char **av, char **envp, t_node *node)
{
	node->ac = ac;
	node->av = av;
	node->envp = envp;
	node->path = find_path(envp, av[2], -1);
	node->path2 = find_path(envp, av[3], -1);
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
