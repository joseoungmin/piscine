/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 14:14:43 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*ft_nodenew(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	new->perv = NULL;
	return (new);
}

void	ft_lstadd_next(t_deque **a, t_node *new)
{
	if (!(*a) || !new)
		return ;
	if (!((*a)->top))
	{
		(*a)->bottom = new;
		(*a)->top = new;
		(*a)->size = 1;
	}
	else
	{
		(*a)->bottom->next = new;
		new->perv = (*a)->bottom;
		(*a)->bottom = new;
		(*a)->size += 1;
	}
}

void	ft_check_sort(t_node *head)
{
	t_node	*point;

	point = head;
	while (point && point->next)
	{
		if (point->num > point->next->num)
			return ;
		point = point->next;
	}
	exit(0);
}

void	av_parse(char **av, t_deque *a, int i, int atoint)
{
	char	**buf;
	int		j;

	if (!a || !av)
		ft_error(0);
	while (av[++i])
	{
		j = -1;
		buf = ft_split(av[i], ' ');
		if (!buf)
			ft_error(1);
		if (buf && !*buf)
			ft_error(2);
		while (buf[++j])
		{
			atoint = ft_pu_atoi(buf[j]);
			if (!ft_check_num(buf[j]) || ft_check_dup(a->top, atoint))
				ft_error(0);
			ft_lstadd_next(&a, ft_nodenew(atoint));
		}
		free_dptr(buf);
	}
	ft_check_sort(a->top);
}

void	total_init(t_total *total)
{
	total->a = ft_calloc(1, sizeof(t_deque));
	if (!total->a)
		ft_error(0);
	total->b = ft_calloc(1, sizeof(t_deque));
	if (!total->b)
		ft_error(0);
}
