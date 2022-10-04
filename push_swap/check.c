/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:10:03 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 10:09:28 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test_deque_print(t_total *deque, char *msg)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		i;
	int		j;
	int		k;

	printf("*****************   < %s >   *****************\n", msg);
	printf("======= deque A =======  ======= deque B =======\n");
	printf("        size: %-10d         size: %-10d\n", deque->a->size, deque->b->size);
	if (deque->a->size > deque->b->size)
		i = deque->a->size;
	else
		i = deque->b->size;;
	cur_a = deque->a->top;
	cur_b = deque->b->top;
	j = 0;
	k = 0;
	while (i > 0)
	{
		if (i <= deque->a->size && i <= deque->b->size)
		{
			printf(" num[%2d] = %12d  num[%2d] = %12d\n", ++j, cur_a->num, ++k, cur_b->num);
			cur_a = cur_a->next;
			cur_b = cur_b->next;
		}
		else if (i <= deque->a->size && i > deque->b->size)
		{
			printf("num[%2d] = %12d\n", ++j, cur_a->num);
			cur_a = cur_a->next;
		}
		else if (i > deque->a->size && i <= deque->b->size)
		{
			printf("                         num[%2d] = %12d\n", ++k, cur_b->num);
			cur_b = cur_b->next;
		}
		i--;
	}
	if (deque->a->top && deque->a->bottom && deque->b->top && deque->b->bottom)
	{
		printf("\n     top = %12d      top = %12d\n", deque->a->top->num, deque->b->top->num);
		printf("  bottom = %12d   bottom = %12d\n", deque->a->bottom->num, deque->b->bottom->num);
	}
	else if (deque->a->top && deque->a->bottom && !deque->b->top && !deque->b->bottom)
	{
		printf("\n     top = %12d  empty\n", deque->a->top->num);
		printf("  bottom = %12d\n", deque->a->bottom->num);
	}
	else if (!deque->a->top && !deque->a->bottom && deque->b->top && deque->b->bottom)
	{
		printf("\nempty                        top = %12d\n", deque->b->top->num);
		printf("                          bottom = %12d\n", deque->b->bottom->num);
	}
	else
		printf("\nempty                    empty\n");
	printf("=======================  =======================\n");
	printf("************************************************\n\n\n");
}
void	test_deque(t_total *deque)
{
//	simple_sort(deque);

	if (deque->a->size == 2)
		ft_sa(deque);
	if (deque->a->size == 3)
		ft_sort_three(deque);
	else
		ft_sort(deque);
}
