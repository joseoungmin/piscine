/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:36:35 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 11:08:52 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_b_top_sort_part_two(t_total *total, int top, int mid, int bot)
{
	if (bot > top && top > mid)
	{
		ft_rb(total);
		ft_sb(total);
		ft_pa(total);
		ft_rrb(total);
		ft_pa(total);
	}
	else if (mid > top && top > bot)
	{
		ft_sb(total);
		ft_pa(total);
		ft_pa(total);
	}
	else
	{
		ft_rb(total);
		ft_sb(total);
		ft_pa(total);
		ft_pa(total);
		ft_rrb(total);
	}
	ft_pa(total);
}

static void	ft_b_top_sort(t_total *total)
{
	const int	top = total->b->top->num;
	const int	mid = total->b->top->next->num;
	const int	bot = total->b->top->next->next->num;

	if (top > mid && mid > bot)
		ft_pa(total);
	else if (mid > bot && bot > top)
	{
		ft_sb(total);
		ft_pa(total);
		ft_sb(total);
	}
	else if (top > bot && bot > mid)
	{
		ft_pa(total);
		ft_sb(total);
	}
	else
	{
		ft_b_top_sort_part_two(total, top, mid, bot);
		return ;
	}
	ft_pa(total);
	ft_pa(total);
}

static void	ft_a_top_sort_part_two(t_total *total, int top, int mid, int bot)
{
	if (!(mid > top && top > bot))
		ft_sa(total);
	ft_ra(total);
	ft_sa(total);
	ft_rra(total);
	ft_sa(total);
}

static void	ft_a_top_sort(t_total *total)
{
	const int	top = total->a->top->num;
	const int	mid = total->a->top->next->num;
	const int	bot = total->a->top->next->next->num;

	if (top < mid && mid < bot)
		;
	else if (mid > bot && bot > top)
	{
		ft_ra(total);
		ft_sa(total);
		ft_rra(total);
	}
	else if (top > bot && bot > mid)
	{
		ft_sa(total);
		ft_ra(total);
		ft_sa(total);
		ft_rra(total);
	}
	else if (bot > top && top > mid)
		ft_sa(total);
	else
		ft_a_top_sort_part_two(total, top, mid, bot);
}

void	top_three_sort(t_total *total, t_deque *stack, int len, int a)
{
	if (!a && len == 1)
		ft_pa(total);
	else if (len == 2)
	{
		if (!a)
		{
			if (stack->top->num < stack->top->next->num)
				ft_sb(total);
			ft_pa(total);
			ft_pa(total);
		}
		else
			if (stack->top->num > stack->top->next->num)
				ft_sa(total);
	}
	else if (len == 3)
	{
		if (a)
			ft_a_top_sort(total);
		else
			ft_b_top_sort(total);
	}
	return ;
}
