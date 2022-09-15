/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:37:46 by seojo             #+#    #+#             */
/*   Updated: 2022/09/15 07:39:49 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	free_dptr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

static char	*ft_join_slash(char *src, char *dest)
{
	char	*buf[2];

	buf[0] = ft_strjoin(src, "/");
	buf[1] = ft_strjoin(buf[0], dest);
	free(buf[0]);
	return (buf[1]);
}

char	*find_path(char **envp, char *cmd, int i)
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
			free_dptr(find_str);
			free_dptr(cmd_buf);
			return (buf);
		}
		free(buf);
	}
	free_dptr(find_str);
	free_dptr(cmd_buf);
	return (cmd);
}

void	init_and_open(char **av, char **envp, t_node *node)
{
	node->av = av;
	node->envp = envp;
	node->in_fd = open(av[1], O_RDONLY);
	node->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (node->out_fd == -1)
		ft_perror(av[4]);
	if (node->in_fd == -1)
	{
		write(2, "pipex: ", 7);
		perror(av[1]);
	}
	else
	{
		ft_dup2(node->in_fd, 0);
		ft_close(node->in_fd);
	}
}
