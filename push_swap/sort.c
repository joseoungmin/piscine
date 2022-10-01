/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:31:26 by seojo             #+#    #+#             */
/*   Updated: 2022/10/01 21:00:12 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////////////////////////////아래
int	ft_cmp(const void *a, const void *b)
{
	int	num1 = *(long *)a;
	int	num2 = *(long *)b;

	if (num1 > num2)
		return (1);
	else if (num1 < num2)
		return (-1);
	return (0);
}
////////////////////////////위

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

void	ft_pivot(t_deque *stack, int *pv_one, int *pv_two, int len)
{
	t_node	*tmp;
	int 	*arr;
	int		i;
	const int	sort_len = len;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		ft_error(1);
	tmp = stack->top;
	i = 0;
	while (len--)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	/////////////////////아래
	qsort(arr, sort_len, sizeof(int), ft_cmp);
	/////////////////////위
	*pv_one = arr[sort_len / 3];
	*pv_two = arr[sort_len * 2 / 3];
	printf("one  %d two  %d\n", *pv_one, *pv_two);

	free(arr);
}

void	recover_ra_rb(t_total *total, int count_ra, int count_rb)
{
	while (count_rb > 0|| count_ra > 0)
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

void	ft_b_top_sort(t_total *total)
{
	const int	top = total->b->top->num;
	const int	mid = total->b->top->next->num;
	const int	bot = total->b->top->next->next->num;

	if (top < mid && mid < bot)// 1 2 3
		return ;
	else if (mid > bot && bot > top)//
	{
		ft_sb(total);
		ft_rb(total);
		ft_sb(total);
		ft_rrb(total);
	}
	else if (top > bot && bot > mid)
	{
		ft_rb(total);
		ft_sb(total);
		ft_rrb(total);
	}
	else if (bot > top && top > mid)
	{
		ft_rb(total);
		ft_sb(total);
		ft_rrb(total);
		ft_sb(total);
	}
	else if (mid > top && top > bot)
		ft_sb(total);
	else
	{
		ft_sb(total);
		ft_rb(total);
		ft_sb(total);
		ft_rrb(total);
	}
}

void	ft_a_top_sort(t_total *total)
{
	const int	top = total->a->top->num;
	const int	mid = total->a->top->next->num;
	const int	bot = total->a->top->next->next->num;

	if (top < mid && mid < bot)
		return ;
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
	else if (mid > top && top > bot)
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

void	top_three_sort(t_total *total, t_deque *stack, int len, int a)
{
	if (len == 2)
	{
		if (a && stack->top->num > stack->top->next->num)
			ft_sa(total);
		else if (!a && stack->top->num < stack->top->next->num)
			ft_sb(total);
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

void	move_to_a(t_total *total, int len)
{
	if (len <= 3)
	{
		top_three_sort(total, total->b, len, 0);
		return ;
	}

	int	count_rb;
	int	count_ra;
	int	count_pa;

	int	pv_one;
	int pv_two;

	ft_pivot(total->b, &pv_one, &pv_two, len);

	count_pa = 0;
	count_ra = 0;
	count_rb = 0;

	printf("len %d\n", len);

	while (len--)
	{
		if (total->b->top->num < pv_one)
			count_rb += (ft_rb(total) == 0);
		else
		{
			count_pa += (ft_pa(total) == 0);
			if (total->a->top->num >= pv_two)
				count_ra += (ft_ra(total) == 0);
		}
	}

	test_deque_print(total, "to_aaaaaaaaaaaa");

	printf("count ra %d count pa %d count rb %d\n", count_ra, count_pa, count_rb);
	move_to_b(total, count_pa - count_ra);
	recover_ra_rb(total, count_ra, count_rb);
	/*move_to_b(total, count_ra);
	move_to_a(total, count_rb);
	*/
}

int a=0;

void	move_to_b(t_total *total, int len)
{
	if (len <= 3)
	{
		printf("len %d\n", len);
		printf("==%d==\n", ++a);
		top_three_sort(total, total->a, len, 1);
		return ;
	}
	int	count_rb;
	int	count_ra;
	int	count_pb;

	int	pv_one;
	int pv_two;

	ft_pivot(total->a, &pv_one, &pv_two, len);

	count_pb = 0;
	count_ra = 0;
	count_rb = 0;
	while (len--)
	{
		if (total->a->top->num >= pv_two)
			count_ra += (ft_ra(total) == 0);
		else
		{
			count_pb += (ft_pb(total) == 0);
			if (total->b->top->num >= pv_one)
				count_rb += (ft_rb(total) == 0);
		}
	}

	test_deque_print(total, "to_b");


	printf("count ra %d count pb %d count rb %d\n", count_ra, count_pb, count_rb);
	recover_ra_rb(total, count_ra, count_rb);
	move_to_b(total, count_ra);
	move_to_a(total, count_rb);
	//move_to_a(total, count_pb - count_rb);
}



void	ft_sort(t_total *total)
{
	move_to_b(total, total->a->size);
	//-------------------------------------------
}
