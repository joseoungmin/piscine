/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:15:28 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 11:09:42 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_total *total)
{
	const int	top = total->a->top->num;
	const int	mid = total->a->top->next->num;
	const int	bot = total->a->bottom->num;

	if (top < mid && mid < bot)
		;
	else if (top > bot && bot > mid)
		ft_ra(total);
	else if (top > mid && mid > bot)
	{
		ft_sa(total);
		ft_rra(total);
	}
	else if (bot > top && top > mid)
		ft_sa(total);
	else if (mid > top && top > bot)
		ft_rra(total);
	else
	{
		ft_rra(total);
		ft_sa(total);
	}
}

void	ft_sort(t_total *total)
{
	int	pv_one;
	int	pv_two;

	if (total->a->size == 5)
	{
		ft_pivot_point(total->a, &pv_one, &pv_two, total->a->size);
		while (total->a->size > 3)
		{
			if (total->a->top->num <= pv_one)
				ft_pb(total);
			else
				ft_ra(total);
		}
		ft_sort_three(total);
		top_three_sort(total, total->b, 2, 0);
	}
	else
		move_to_b(total, total->a->size);
}
