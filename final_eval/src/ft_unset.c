/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:32:25 by seojo             #+#    #+#             */
/*   Updated: 2022/12/02 23:58:31 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	check_envp_cmd(char *cmd)
{
	if (!cmd || !*cmd || (!ft_isalpha(*cmd) && !(*cmd == '_')))
		return (-1);
	while (*++cmd)
	{
		if (*cmd == '=')
			return (0);
		if (!(ft_isalnum(*cmd) || *cmd == '_'))
			return (-1);
	}
	return (1);
}

int	ft_unset(t_env_lst *lst, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		if (check_envp_cmd(cmd[i]) != 1)
			return (error_cmd_path("unset", cmd[i], \
						"not a valid identifier", 1));
		del_env_node(lst, cmd[i]);
	}
	return (0);
}
