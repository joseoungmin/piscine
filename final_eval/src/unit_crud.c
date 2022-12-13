/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_crud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:49:52 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 15:22:50 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crud.h"

static t_cmd_unit	*create_unit(t_env_lst *lst, char *cmd, int *exit_stat)
{
	t_cmd_unit	*new_unit;

	new_unit = ft_calloc(1, sizeof(t_cmd_unit));
	if (new_unit == NULL)
		error_cmd("malloc", strerror(12), 1);
	if (del_redir_in_cmd(new_unit, cmd, exit_stat) == 1)
	{
		if (*exit_stat != 1)
			*exit_stat = 258;
		return (NULL);
	}
	new_unit->cmd = split_quotes(lst, cmd, ' ', *exit_stat);
	if (new_unit == NULL)
		error_cmd("malloc", strerror(12), 1);
	return (new_unit);
}

void	del_one_unit(t_cmd_unit *unit)
{
	int	i;

	i = 0;
	while (unit->cmd[i] != NULL)
		ft_free(unit->cmd[i++]);
	free(unit->cmd);
	unit->cmd = NULL;
	del_all_redir(unit->redir);
	unit->next = NULL;
	free(unit);
	unit = NULL;
}

static t_cmd_unit	*all_clear_cmd_unit(t_cmd_unit *unit)
{
	t_cmd_unit	*rm_point;
	int			i;

	if (unit == NULL)
		return (NULL);
	rm_point = unit;
	while (rm_point != NULL)
	{
		i = 0;
		unit = unit->next;
		del_all_redir(rm_point->redir);
		rm_point->next = NULL;
		while (rm_point->cmd[i])
			ft_free(rm_point->cmd[i++]);
		free(rm_point->cmd);
		rm_point->cmd = NULL;
		free(rm_point);
		rm_point = unit;
	}
	return (NULL);
}

t_cmd_unit	*split_pipe_cmd(t_env_lst *lst, char *cmd, int *exit_stat)
{
	t_cmd_unit	*rt_unit;
	t_cmd_unit	*unit_point;
	char		**pipe_split;
	int			i;

	pipe_split = msplit(cmd, '|');
	if (pipe_split == NULL)
		error_cmd("malloc", strerror(12), 1);
	i = 0;
	rt_unit = create_unit(lst, pipe_split[i++], exit_stat);
	ft_free(pipe_split[0]);
	if (rt_unit == NULL)
		return (NULL);
	unit_point = rt_unit;
	while (pipe_split[i])
	{
		unit_point->next = create_unit(lst, pipe_split[i], exit_stat);
		if (unit_point->next == NULL)
			return (all_clear_cmd_unit(rt_unit));
		unit_point = unit_point->next;
		ft_free(pipe_split[i]);
		i++;
	}
	free(pipe_split);
	return (rt_unit);
}
