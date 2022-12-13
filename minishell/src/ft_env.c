/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:08 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 18:35:57 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	ft_env(t_env_lst *lst)
{
	t_env_node	*node;

	node = lst->top;
	while (node != NULL)
	{
		if (node->value == NULL)
			node = node->next;
		else
		{
			printf("%s=%s\n", node->key, node->value);
			node = node->next;
		}
	}
	return (0);
}

void	free_env_lst(t_env_lst *lst)
{
	if (!lst)
		return ;
	if (!lst->top)
	{
		free(lst);
		return ;
	}
	while (lst->top->next)
	{
		lst->top = lst->top->next;
		free(lst->top->prev->key);
		lst->top->prev->key = NULL;
		free(lst->top->prev->value);
		lst->top->prev->value = NULL;
		free(lst->top->prev);
		lst->top->prev = NULL;
	}
	free(lst->top->key);
	lst->top->key = NULL;
	free(lst->top->value);
	lst->top->value = NULL;
	free(lst->top);
	lst->top = NULL;
	free(lst);
	lst = NULL;
}

t_env_lst	*envp_cpy(char **envp)
{
	int			i;
	char		**split;
	t_env_lst	*rt_lst;

	if (!envp[0])
		return (NULL);
	rt_lst = ft_calloc(1, sizeof(t_env_lst));
	if (!rt_lst)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		split = ft_split(envp[i], '=');
		if (!split)
		{
			free_env_lst(rt_lst);
			return (NULL);
		}
		add_new_node(rt_lst, split[0]);
		rt_lst->bot->value = split[1];
		ft_free(split[0]);
		free(split);
	}
	return (rt_lst);
}
