/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:07:24 by seojo             #+#    #+#             */
/*   Updated: 2022/12/03 00:04:25 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	sort_arr(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		j = 1;
		while (arr[j])
		{
			if (ft_strncmp(arr[j - 1], arr[j], ft_strlen(arr[j - 1]) > 0))
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static char	**rt_env_arr(t_env_lst *lst)
{
	t_env_node	*node;
	char		**env_arr;
	int			i;
	int			j;

	node = lst->top;
	i = -1;
	while (++i >= 0 && node != NULL)
		node = node->next;
	env_arr = ft_calloc(i + 1, sizeof(char *));
	if (!env_arr)
		return (NULL);
	j = -1;
	node = lst->top;
	while (++j < i)
	{
		env_arr[j] = node->key;
		node = node->next;
	}
	env_arr[j] = NULL;
	sort_arr(env_arr);
	return (env_arr);
}

static int	print_export(t_env_lst *lst)
{
	t_env_node	*node;
	char		**env_arr;
	int			i;

	env_arr = rt_env_arr(lst);
	if (!env_arr)
		return (1);
	i = -1;
	while (env_arr[++i])
	{
		node = find_node(lst, env_arr[i]);
		if (node->value == NULL)
			printf("declare -x %s\n", node->key);
		else
			printf("declare -x %s=\"%s\"\n", node->key, node->value);
	}
	free(env_arr);
	return (0);
}

static char	**split_export(char *cmd)
{
	char	**rt_cmd;
	int		i;
	int		j;

	rt_cmd = ft_calloc(sizeof(char *), 3);
	if (!rt_cmd)
		return (NULL);
	i = 0;
	while (cmd[i] && cmd[i] != '=')
		i++;
	rt_cmd[0] = ft_substr(cmd, 0, i);
	if (!rt_cmd[0])
		return (ft_free_dptr(rt_cmd, 1));
	j = i;
	while (cmd[j])
		j++;
	rt_cmd[1] = ft_substr(cmd, i + 1, j);
	if (!rt_cmd[0])
		return (ft_free_dptr(rt_cmd, 2));
	rt_cmd[2] = NULL;
	return (rt_cmd);
}

int	ft_export(t_env_lst *lst, char **cmd)
{
	int		i;
	char	**split;

	if (!cmd[1])
		if (print_export(lst))
			return (error_cmd("export", strerror(12), 0));
	i = 0;
	while (cmd[++i] != NULL)
	{
		if (check_envp_cmd(cmd[i]) == -1)
			return (error_cmd_path("export", cmd[i], \
						"not a valid identifier", 1));
		else if (check_envp_cmd(cmd[i]) == 1)
			env_node_update_or_create(lst, cmd[i], NULL);
		else
		{
			split = split_export(cmd[i]);
			if (!split)
				return (error_cmd("export", strerror(12), 0));
			env_node_update_or_create(lst, split[0], split[1]);
			free(split);
		}
	}
	return (0);
}
