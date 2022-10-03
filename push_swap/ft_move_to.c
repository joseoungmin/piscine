/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:05:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 11:08:12 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	recover_ra_rb(t_total *total, int count_ra, int count_rb)
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

static void	init_cnt(int *count)
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
}

static void	move_to_a(t_total *total, int len)
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
	move_to_b(total, count[PA] - count[RA]);
	recover_ra_rb(total, count[RA], count[RB]);
	move_to_b(total, count[RA]);
	move_to_a(total, count[RB]);
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
