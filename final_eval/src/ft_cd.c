/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:10:56 by seojo             #+#    #+#             */
/*   Updated: 2022/12/06 21:31:07 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	oldpwd_update(t_env_lst *lst)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
		return (error_cmd("cd", strerror(12), 0));
	if (env_node_update_or_create(lst, "OLDPWD", buf))
		return (error_cmd("cd", strerror(12), 0));
	return (0);
}

static int	move_to_oldpwd(t_env_lst *lst)
{
	const t_env_node	*node = find_node(lst, "OLDPWD");
	char				*cp_value;

	if (node == NULL)
		return (error_cmd("cd", "OLDPWD not set", 0));
	cp_value = ft_strdup(node->value);
	if (cp_value == NULL)
		error_cmd("cd", strerror(12), 1);
	if (oldpwd_update(lst))
		return (1);
	printf("%s\n", cp_value);
	if (chdir(cp_value))
	{
		ft_free(cp_value);
		return (error_cmd("cd", strerror(errno), 0));
	}
	ft_free(cp_value);
	return (0);
}

int	ft_cd(t_env_lst *lst, char **cmd)
{
	if (!cmd[1] || !strncmp(cmd[1], "~", 2))
	{
		if (oldpwd_update(lst))
			return (1);
		if (chdir(getenv("HOME")) == -1)
			return (error_cmd_path("cd", cmd[1], strerror(errno), 0));
	}
	else if (!strncmp(cmd[1], "-\0", 2))
	{
		if (move_to_oldpwd(lst))
			return (1);
	}
	else
	{
		if (chdir(cmd[1]))
		{
			if (oldpwd_update(lst))
				return (1);
			return (error_cmd_path("cd", cmd[1], strerror(errno), 0));
		}
	}
	return (0);
}
