/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_crud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <seojo@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:57 by marvin            #+#    #+#             */
/*   Updated: 2022/12/10 18:35:05 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crud.h"

t_env_node	*find_node(t_env_lst *lst, char *key)
{
	t_env_node	*rt_node;
	const int	len = ft_strlen(key) + 1;

	if (lst->top == NULL)
		return (NULL);
	rt_node = lst->top;
	while (ft_strncmp(rt_node->key, key, len) != 0 && rt_node->next != NULL)
		rt_node = rt_node->next;
	if (ft_strncmp(rt_node->key, key, len) != 0)
		return (NULL);
	return (rt_node);
}

t_env_node	*add_new_node(t_env_lst *lst, char *key)
{
	t_env_node	*new;

	new = ft_calloc(1, sizeof(t_env_node));
	if (!new)
		error_cmd("malloc", strerror(12), 1);
	if (lst->top != NULL)
	{
		lst->bot->next = new;
		new->prev = lst->bot;
		lst->bot = new;
	}
	else
	{
		lst->top = new;
		lst->bot = new;
	}
	new->key = ft_strdup(key);
	return (new);
}

static void	free_del_node(t_env_node *del_node)
{
	del_node->next = NULL;
	del_node->prev = NULL;
	free(del_node->key);
	del_node->key = NULL;
	free(del_node->value);
	del_node->value = NULL;
	free(del_node);
	del_node = NULL;
}

void	del_env_node(t_env_lst *lst, char *key)
{
	t_env_node	*del_node;

	del_node = find_node(lst, key);
	if (!lst->top || !del_node)
		return ;
	if (!del_node->prev && del_node->next)
	{
		lst->top = lst->top->next;
		lst->top->prev = NULL;
	}
	else if (!del_node->next && del_node->prev)
	{
		lst->bot = lst->bot->prev;
		lst->bot->next = NULL;
	}
	else if (del_node->next && del_node->prev)
	{
		del_node->prev->next = del_node->next;
		del_node->next->prev = del_node->prev;
	}
	free_del_node(del_node);
}

int	env_node_update_or_create(t_env_lst *lst, char *key, char *value)
{
	t_env_node	*node;

	if (lst->top == NULL)
	{
		node = add_new_node(lst, key);
		if (node == NULL)
			return (1);
	}
	else
	{
		node = find_node(lst, key);
		if (node == NULL)
			node = add_new_node(lst, key);
	}
	if (value == NULL && node->value == NULL)
		node->value = NULL;
	else if (value == NULL && node->value != NULL)
		return (0);
	else
	{
		ft_free(node->value);
		node->value = value;
	}
	return (0);
}
