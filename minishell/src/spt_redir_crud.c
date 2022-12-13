/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_redir_crud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:02 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 18:26:48 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crud.h"

void	del_all_redir(t_redir *redir)
{
	t_redir	*rm_point;

	if (redir == NULL)
		return ;
	if (redir->next == NULL)
	{
		redir->next = NULL;
		ft_free(redir->doc);
		ft_free(redir->filename);
		free(redir);
		redir = NULL;
	}
	rm_point = redir;
	while (rm_point != NULL)
	{
		redir = redir->next;
		rm_point->next = NULL;
		ft_free(rm_point->doc);
		ft_free(rm_point->filename);
		free(rm_point);
		rm_point = redir;
	}
}

void	idx_plus(char *cmd, int *i)
{
	char	c;

	if (cmd[*i] == '\'' || cmd[*i] == '\"')
	{
		c = cmd[(*i)++];
		while (cmd[*i] != c && cmd[*i] != '\0')
			(*i)++;
	}
}

int	type_error(char *cmd, int type, int *i)
{
	while (cmd[*i] == ' ')
		(*i)++;
	if (type != -1 && (cmd[*i] == '<' || cmd[*i] == '>'))
		return (error_syntax(&cmd[*i]));
	while (type != -1 && cmd[*i] != '\0' && cmd[*i] == ' ')
		*i += 1;
	if (type != -1 && cmd[*i] == '\0')
		return (error_syntax("newline"));
	return (0);
}

int	rt_idx(char *cmd, char c, int *i)
{
	int	j;

	j = ++(*i);
	while (cmd[*i] != c && cmd[*i] != '\0')
		(*i)++;
	return (*i - j);
}

int	rt_copy(char *cmd, int *i)
{
	int	j;

	j = *i;
	while (cmd[*i] != ' ' && cmd[*i] != '\0' \
			&& cmd[*i] != '\'' && cmd[*i] != '\"')
		(*i)++;
	return (*i - j);
}
