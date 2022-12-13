/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:36:33 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 03:20:09 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_close.h"

int	ft_access(char *cmd_path, int num)
{
	struct stat	buffer;

	if (stat(cmd_path, &buffer) != 0)
		return (1);
	if (!(buffer.st_mode & S_IFMT))
		return (1);
	if (num == ROK)
		if (buffer.st_mode & S_IRUSR)
			return (0);
	if (num == WOK)
		if (buffer.st_mode & S_IWUSR)
			return (0);
	if (num == XOK)
		if (buffer.st_mode & S_IXUSR)
			return (0);
	if (num == FOK)
		return (0);
	return (1);
}

int	ft_open(char *file, int type)
{
	int	fd;

	fd = -1;
	if (type == READ)
	{
		if (ft_access(file, FOK))
			return (error_cmd(file, strerror(2), 0));
		if (ft_access(file, ROK))
			return (error_cmd(file, strerror(13), 0));
		fd = open(file, O_RDONLY, 0644);
	}
	else if (type == WRITE || type == APPEND)
	{
		if (!ft_access(file, FOK) && ft_access(file, WOK))
			return (error_cmd(file, strerror(13), 0));
		if (type == WRITE)
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	return (fd);
}

static int	open_dup_close(t_redir *redi, int type)
{
	int	fd;

	fd = 0;
	if (type == READ || type == HEREDOC)
	{
		if (type == READ)
			fd = ft_open(redi->filename, READ);
		else
			fd = ft_open(redi->doc, READ);
		if (fd < 2)
			return (1);
		ft_dup2(fd, STDIN_FILENO);
		ft_close(fd);
	}
	else if (type == WRITE || type == APPEND)
	{
		fd = ft_open(redi->filename, type);
		if (fd < 2)
			return (1);
		ft_dup2(fd, STDOUT_FILENO);
		ft_close(fd);
	}
	return (0);
}

int	dup_redirection(t_cmd_unit *unit, int stdoutfd, int *exit_stat)
{
	t_redir	*tmp;
	int		type[4];

	type[0] = 0;
	type[1] = 0;
	type[2] = 0;
	type[3] = 0;
	if (unit->redir == NULL)
	{
		if (unit->next == NULL)
			ft_dup2(stdoutfd, STDOUT_FILENO);
		return (0);
	}
	tmp = unit->redir;
	while (tmp)
	{
		type[tmp->type] = 1;
		*exit_stat = open_dup_close(tmp, tmp->type);
		if (*exit_stat)
			return (1);
		tmp = tmp->next;
	}
	if (unit->next == NULL && !(type[WRITE] == 1 || type[APPEND]) == 1)
		ft_dup2(stdoutfd, STDOUT_FILENO);
	return (0);
}
