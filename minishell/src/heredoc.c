/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:14 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 03:02:37 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unlink_docfile(void)
{
	int		i;
	char	*name;
	char	*itoa_idx;
	char	*del_doc;

	i = 1;
	name = ft_strdup(".heredoc");
	while (i < 500)
	{
		itoa_idx = ft_itoa(i);
		if (name == NULL || itoa_idx == NULL)
			error_cmd("malloc", strerror(12), 1);
		del_doc = ft_strjoin(name, itoa_idx);
		if (del_doc == NULL)
			error_cmd("malloc", strerror(12), 1);
		i++;
		unlink(del_doc);
		ft_free(itoa_idx);
		ft_free(del_doc);
	}
	ft_free(name);
}

static int	make_docfile(char **doc, int idx)
{
	int			fd;
	char		*name;
	char		*itoa_idx;

	name = ft_strdup(".heredoc");
	itoa_idx = ft_itoa(idx);
	if (!name || !itoa_idx)
		error_cmd("malloc", strerror(12), 1);
	*doc = ft_strjoin(name, itoa_idx);
	if (!*doc)
		error_cmd("malloc", strerror(12), 1);
	ft_free(itoa_idx);
	ft_free(name);
	fd = ft_open(*doc, WRITE);
	return (fd);
}

static void	go_heredoc(char *end, int fd)
{
	char		*line;

	while (TRUE)
	{
		line = readline("> ");
		if (!line)
		{
			printf("\033[1A");
			printf("\033[2C");
			break ;
		}
		if (!ft_strncmp(line, end, ft_strlen(end) + 1))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	ft_close(fd);
	exit(0);
}

static int	ft_heredoc(char *end, char **doc, int idx)
{
	const int	fd = make_docfile(doc, idx);
	pid_t		pid;
	int			exit_stat;

	sig_handler(IGNORE, IGNORE);
	pid = ft_fork();
	if (pid == 0)
	{
		sig_handler(HERE, GDSET);
		go_heredoc(end, fd);
	}
	exit_stat = ft_wait(pid);
	if (exit_stat)
		return (1);
	sig_handler(GDSET, GDSET);
	return (0);
}

int	check_heredoc(t_cmd_unit *unit)
{
	t_cmd_unit	*tmp;
	t_redir		*redir;
	int			i;

	i = 1;
	tmp = unit;
	while (tmp)
	{
		redir = tmp->redir;
		while (redir)
		{
			if (redir->type == HEREDOC)
				if (ft_heredoc(redir->filename, &redir->doc, i))
					return (1);
			redir = redir->next;
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}
