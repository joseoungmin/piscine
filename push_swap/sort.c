/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:31:26 by seojo             #+#    #+#             */
/*   Updated: 2022/09/27 19:54:13 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_total *total)
{
	const int	top = total->a->top->num;
	const int	mid  = total->a->top->next->num;
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
