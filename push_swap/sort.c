/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:31:26 by seojo             #+#    #+#             */
/*   Updated: 2022/10/02 23:43:30 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_total *total)
{
	const int	top = total->a->top->num;
	const int	mid = total->a->top->next->num;
	const int	bot = total->a->bottom->num;

	if (top > mid && mid > bot)
	{
		ft_ra(total);
		ft_sa(total);
	}
	else if (top > mid && top < bot)
		ft_sa(total);
	else if (top > mid && mid < bot)
		ft_ra(total);
	else if (mid > top && top > bot)
		ft_rra(total);
	else
	{
		ft_rra(total);
		ft_sa(total);
	}
}

void	recover_ra_rb(t_total *total, int count_ra, int count_rb)
{
	while (count_rb > 0 || count_ra > 0)
	{
		if (count_rb > 0 && count_ra > 0)
		{
			count_rb--;
			count_ra--;
			ft_rrr(total);
			continue ;
		}
		if (count_rb > 0)
		{
			count_rb--;
			ft_rrb(total);
		}
		if (count_ra > 0)
		{
			count_ra--;
			ft_rra(total);
		}
	}
}

void	ft_b_top_sort_part_two(t_total *total, int top, int mid, int bot)
{
	if (bot > top && top > mid)
	{
		ft_rb(total);
		ft_sb(total);
		ft_pa(total);
		ft_rrb(total);
		ft_pa(total);
		ft_pa(total);
	}
	else if (mid > top && top > bot)
	{
		ft_sb(total);
		ft_pa(total);
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
		ft_pa(total);
	}
}

void	ft_b_top_sort(t_total *total)
{
	const int	top = total->b->top->num;
	const int	mid = total->b->top->next->num;
	const int	bot = total->b->top->next->next->num;

	if (top > mid && mid > bot)
		;
	else if (mid > bot && bot > top)
	{
		ft_sa(total);
		ft_pa(total);
		ft_sa(total);
		ft_pa(total);
		ft_pa(total);
	}
	else if (top > bot && bot > mid)
	{
		ft_pa(total);
		ft_sb(total);
		ft_pa(total);
		ft_pa(total);
	}
	else
		ft_b_top_sort_part_two(total, top, mid, bot);
}

void	ft_a_top_sort_part_two(t_total *total, int top, int mid, int bot)
{
	if (mid > top && top > bot)
	{
		ft_ra(total);
		ft_sa(total);
		ft_rra(total);
		ft_sa(total);
	}
	else
	{
		ft_sa(total);
		ft_ra(total);
		ft_sa(total);
		ft_rra(total);
		ft_sa(total);
	}
}

void	ft_a_top_sort(t_total *total)
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
		if (a)
		{
			if (a && stack->top->num > stack->top->next->num)
				ft_sa(total);
		}
		else
		{
			if (stack->top->num < stack->top->next->num)
				ft_sb(total);
			ft_pa(total);
			ft_pa(total);
		}
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

void	init_cnt(int *count)
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
}



#include <stdio.h>

/*
void	move_to_a(t_total *total, int len)
{
	int	count[4];
	int	pv_one;
	int	pv_two;

	init_cnt(count);
	if (len <= 3)
		return (top_three_sort(total, total->b, len, 0));
	ft_pivot_point(total->b, &pv_one, &pv_two, len);
	while (len--)
	{
		if (total->b->top->num < pv_one)
			count[RB] += (ft_rb(total) == 0);
		else
		{
			count[PA] += (ft_pa(total) == 0);
			if (total->a->top->num <= pv_two)
				count[RA] += (ft_ra(total) == 0);
		}
	}
	printf("PA %d RA %d RB %d\n", count[PA], count[RA], count[RB]);
	return ;
	move_to_b(total, count[PA] - count[RA]);
	recover_ra_rb(total, count[RA], count[RB]);
	move_to_b(total, count[RA]);
	move_to_a(total, count[RB]);
}
*/
void	move_to_a(t_total *total, int len)
{
	unsigned long long	count;
	int	pv_one;
	int	pv_two;

	count = 0;
	if (len <= 3)
		return (top_three_sort(total, total->b, len, 0));
	ft_pivot_point(total->b, &pv_one, &pv_two, len);
	while (len--)
	{
		if (total->b->top->num < pv_one)
			count += (unsigned long long)(ft_rb(total) == 0) << 32;
		else
		{
			count += (ft_pa(total) == 0) << 16;
			if (total->a->top->num <= pv_two)
				count += (ft_ra(total) == 0);
		}
	}
	printf("PA %lld RA %lld RB %lld\n", count << 32 >> 48, count << 48 >> 48, count >> 32);
	return ;
	/*
	move_to_b(total, count[PA] - count[RA]);
	recover_ra_rb(total, count[RA], count[RB]);
	move_to_b(total, count[RA]);
	move_to_a(total, count[RB]);*/
}

void	move_to_b(t_total *total, int len)
{
	int	count[4];
	int	pv_one;
	int	pv_two;

	init_cnt(count);
	if (len <= 3)
		return (top_three_sort(total, total->a, len, 1));
	ft_pivot_point(total->a, &pv_one, &pv_two, len);
	while (len--)
	{
		if (total->a->top->num >= pv_two)
			count[RA] += (ft_ra(total) == 0);
		else
		{
			count[PB] += (ft_pb(total) == 0);
			if (total->b->top->num >= pv_one)
				count[RB] += (ft_rb(total) == 0);
		}
	}
	recover_ra_rb(total, count[RA], count[RB]);
	move_to_b(total, count[RA]);
	move_to_a(total, count[RB]);
	move_to_a(total, count[PB] - count[RB]);
}

void	ft_sort(t_total *total)
{
	move_to_b(total, total->a->size);
}
