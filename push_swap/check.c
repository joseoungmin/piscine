#include "push_swap.h"
#include <stdio.h>

void	test_deque_print(t_total *deque, char *msg)
{
	t_node	*cur_a;
	t_node	*cur_b;
	size_t	i;
	int		j, k;

	printf("*****************   < %s >   *****************\n", msg);
	printf("======= deque A =======  ======= deque B =======\n");
	printf("        size: %-10zu         size: %-10zu\n", deque->a->size, deque->b->size);
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
			printf("data[%2d] = %12d  data[%2d] = %12d\n", ++j, cur_a->data, ++k, cur_b->data);
			cur_a = cur_a->next;
			cur_b = cur_b->next;
		}
		else if (i <= deque->a->size && i > deque->b->size)
		{
			printf("data[%2d] = %12d\n", ++j, cur_a->data);
			cur_a = cur_a->next;
		}
		else if (i > deque->a->size && i <= deque->b->size)
		{
			printf("                         data[%2d] = %12d\n", ++k, cur_b->data);
			cur_b = cur_b->next;
		}
		i--;
	}
	if (deque->a->top && deque->a->bottom && deque->b->top && deque->b->bottom)
	{
		printf("\n     top = %12d       top = %12d\n", deque->a->top->data, deque->b->top->data);
		printf("  bottom = %12d    bottom = %12d\n", deque->a->bottom->data, deque->b->bottom->data);
	}
	else if (deque->a->top && deque->a->bottom && !deque->b->top && !deque->b->bottom)
	{
		printf("\n     top = %12d  empty\n", deque->a->top->data);
		printf("  bottom = %12d\n", deque->a->bottom->data);
	}
	else if (!deque->a->top && !deque->a->bottom && deque->b->top && deque->b->bottom)
	{
		printf("\nempty                         top = %12d\n", deque->b->top->data);
		printf("                           bottom = %12d\n", deque->b->bottom->data);
	}
	else
		printf("\nempty                    empty\n");
	printf("=======================  =======================\n");
	printf("************************************************\n\n\n");
}
void	test_deque(t_total *deque)
{
//	simple_sort(deque);
//	test_deque_print(deque, "simple");
	pb(deque);
	pb(deque);
	pb(deque);
	pb(deque);
	pb(deque);
	pb(deque);
	pb(deque);
	test_deque_print(deque, "7 pb");
	rr(deque);
	rr(deque);
	test_deque_print(deque, "2 rr");
	sa(deque);
	test_deque_print(deque, " sa ");
}
