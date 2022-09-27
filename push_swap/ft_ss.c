/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:45:29 by seojo             #+#    #+#             */
/*   Updated: 2022/09/26 20:29:20 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_deque *stack)
{
	if (stack->size < 2)
		return (1);
	stack->top->num ^= stack->top->next->num;
	stack->top->next->num ^= stack->top->num;
	stack->top->num ^= stack->top->next->num;
	return (0);
}

int	ft_sa(t_total *total)
{
	return (ft_swap(total->a));
}

int	ft_sb(t_total *total)
{
	return (ft_swap(total->b));
}

int	ft_ss(t_total *total)
{
	return (ft_swap(total->a) || ft_swap(total->b));
}
