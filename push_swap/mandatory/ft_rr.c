/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:32:21 by seojo             #+#    #+#             */
/*   Updated: 2022/10/01 17:26:37 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_deque *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return (0);
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->perv = NULL;
	tmp->next = NULL;
	tmp->perv = stack->bottom;
	stack->bottom->next = tmp;
	stack->bottom = tmp;
	return (0);
}

int	ft_ra(t_total *total)
{
	write(1, "ra\n", 3);
	return (ft_rotate(total->a));
}

int	ft_rb(t_total *total)
{
	write(1, "rb\n", 3);
	return (ft_rotate(total->b));
}

int	ft_rr(t_total *total)
{
	write(1, "rr\n", 3);
	return (ft_rotate(total->a) || ft_rotate(total->b));
}
