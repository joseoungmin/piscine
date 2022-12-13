/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_crud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:36:00 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 18:26:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crud.h"

int	check_redir_type(char *cmd, int *i)
{
	int			type;
	int			rt;
	const char	arr[5][3] = {
		"<", ">", ">>", "<<"
	};

	type = 4;
	while (--type >= 0)
	{
		rt = ft_strncmp(cmd, arr[type], ft_strlen(arr[type]));
		if (rt == 0)
			break ;
	}
	if (type != -1)
	{
		*i += 1;
		cmd[0] = ' ';
		if (type == HEREDOC || type == APPEND)
		{
			cmd[1] = ' ';
			*i += 1;
		}
		return (type);
	}
	return (-1);
}

char	*add_filename(char **cmd, int *i)
{
	char	*filename;
	char	*before;
	char	*after;
	int		idx;

	filename = ft_strdup("");
	while ((*cmd)[*i] != '\0' && (*cmd)[*i] != ' ' && (*cmd)[*i] != '\0')
	{
		idx = *i;
		before = filename;
		if ((*cmd)[*i] == '\'' || (*cmd)[*i] == '\"')
			after = ft_substr(*cmd, *i + 1, rt_idx(*cmd, (*cmd)[*i], i));
		else
			after = ft_substr((*cmd), *i, rt_copy(*cmd, i));
		while (idx < *i)
			(*cmd)[idx++] = ' ';
		if ((*cmd)[idx] != '\0')
			(*cmd)[idx] = ' ';
		filename = ft_strjoin(before, after);
		ft_free(before);
		ft_free(after);
		if ((*cmd)[*i] != ' ' && (*cmd)[*i] != '\0')
			(*i)++;
	}
	return (filename);
}

t_redir	*create_new_redir(int type, char *cmd, int *i)
{
	t_redir	*redir;

	redir = ft_calloc(sizeof(t_redir), 1);
	if (redir == NULL)
		error_cmd("malloc", strerror(12), 1);
	redir->type = type;
	redir->filename = add_filename(&cmd, i);
	return (redir);
}

static void	redir_add_back(t_redir **redir, t_redir *new)
{
	t_redir	*last_redir;

	if (!redir || !new)
		return ;
	if (!*redir)
		*redir = new;
	else
	{
		last_redir = *redir;
		while (last_redir->next != NULL)
			last_redir = last_redir->next;
		last_redir->next = new;
	}
}

int	del_redir_in_cmd(t_cmd_unit *unit, char *cmd, int *exit_stat)
{
	t_redir	*new_redir;
	int		type;
	int		i;

	i = 0;
	while (cmd[i] != '\0')
	{
		idx_plus(cmd, &i);
		type = check_redir_type(&cmd[i], &i);
		if (type == -1 && i++)
			continue ;
		if (type_error(cmd, type, &i))
			return (258);
		if ((cmd + i) != NULL && cmd[i] != '\0' && type != -1)
		{
			new_redir = create_new_redir(type, cmd, &i);
			if (*exit_stat)
				return (1);
			if (new_redir == NULL)
				return (error_syntax(&cmd[i]));
			redir_add_back(&unit->redir, new_redir);
		}
	}
	return (0);
}
