/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmdline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:24:38 by seojo             #+#    #+#             */
/*   Updated: 2022/12/09 17:26:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	pass_quotes(char *cmd, int *i)
{
	const char	c = cmd[*i];

	(*i)++;
	while (cmd[*i] != c)
		(*i)++;
	(*i)++;
}

void	is_pipe(char **cmd)
{
	char	*add_cmd;
	char	*rt_cmd;

	add_cmd = readline("> ");
	rt_cmd = ft_strjoin(*cmd, add_cmd);
	ft_free(*cmd);
	*cmd = rt_cmd;
	ft_free(add_cmd);
}

int	check_pipe(char **cmd)
{
	char	checker;
	int		i;

	i = 0;
	checker = ' ';
	while ((*cmd)[i])
	{
		if ((*cmd)[i] == '\'' || (*cmd)[i] == '\"')
		{
			pass_quotes(*cmd, &i);
			continue ;
		}
		if ((*cmd)[i] != ' ')
		{
			if ((checker == '|' || checker == ' ') && (*cmd)[i] == '|')
				return (error_syntax("|"));
			checker = (*cmd)[i];
		}
		i++;
	}
	if (checker == '|')
		is_pipe(cmd);
	return (0);
}

int	check_blank(char *cmd)
{
	char	c;
	int		i;

	c = ' ';
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != ' ')
			c = cmd[i];
		i++;
	}
	if (c == ' ')
		return (1);
	return (0);
}

int	check_syntax(char **cmd, int *exit_stat)
{
	if (check_blank(*cmd))
	{
		ft_free(*cmd);
		return (1);
	}
	if (check_pipe(cmd))
	{
		ft_free(*cmd);
		*exit_stat = 258;
		return (1);
	}
	return (0);
}
