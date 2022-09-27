/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:49:49 by seojo             #+#    #+#             */
/*   Updated: 2022/09/27 18:43:40 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_deque *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return (1);
	tmp = stack->bottom;
	stack->bottom = stack->bottom->perv;
	stack->bottom->next = NULL;
	tmp->perv = NULL;
	tmp->next = stack->top;
	stack->top->perv = tmp;
	stack->top = tmp;
	return (0);
}

int	ft_rra(t_total *total)
{
	return (ft_rotate(total->a));
}

int	ft_rrb(t_total *total)
{
	return (ft_rotate(total->b));
}

int	ft_rrr(t_total *total)
{
	return (ft_rotate(total->a) || ft_rotate(total->b));
}
