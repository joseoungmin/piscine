/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:21:37 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 14:28:03 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_push(t_deque *stack, int push)
{
	t_node	*new;

	new = ft_nodenew(push);
	if (!new)
		ft_error(2);
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->top->perv = new;
		new->next = stack->top;
		stack->top = new;
	}
	stack->size++;
}

static int	ft_pop(t_deque *stack)
{
	const int	rt_num = stack->top->num;

	if (stack->size < 2)
	{
		free(stack->top);
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->perv->next = NULL;
		free(stack->top->perv);
		stack->top->perv = NULL;
	}
	stack->size--;
	return (rt_num);
}

static int	ft_move_to_top(t_deque *from, t_deque *to)
{
	if (from->size < 1)
		return (1);
	ft_push(to, ft_pop(from));
	return (0);
}

int	ft_pb(t_total *total)
{
	return (ft_move_to_top(total->a, total->b));
}

int	ft_pa(t_total *total)
{
	return (ft_move_to_top(total->b, total->a));
}
