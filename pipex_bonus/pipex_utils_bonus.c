/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:37:46 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 02:20:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_join_slash(char *src, char *dest)
{
	char	*buf[2];

	buf[0] = ft_strjoin(src, "/");
	buf[1] = ft_strjoin(buf[0], dest);
	free_sptr(buf[0]);
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
		free_sptr(buf);
	}
	free_dptr(find_str);
	free_dptr(cmd_buf);
	return (NULL);
}

void	node_init(int ac, char **av, char **envp, t_node *node)
{
	node->hd = 0;
	if (ft_strncmp("heredoc", av[1], 7) == 0)
		node->hd = 1;
	node->ac = ac;
	node->av = av;
	node->envp = envp;
	node->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (node->out_fd == -1)
		ft_perror(av[ac - 1]);
	node->in_fd = open(av[1 + node->hd], O_RDONLY);
	if (node->in_fd != -1)
	{
		ft_dup2(node->in_fd, 0);
		ft_close(node->in_fd);
	}
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
