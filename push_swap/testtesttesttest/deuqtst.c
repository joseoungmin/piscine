#include "../push_swap.h"
#include <stdio.h>

void ft_numset1(t_total *deque)
{
	deque->a.top = (t_dlst *)malloc(sizeof(t_dlst));
	for(int i=10; i<20; i++)
		deque->a.top->num = i;
}
void ft_numset2(t_total *deque)
{
	for (int i = 0; i<10; i++)
	{
		deque->a.size = i;
	}
}

void ft_numset3(t_deque *deque)
{
	for(int i = 10; i>0; i--)
	{
		deque->size = i;
	}	
}

int main(void)
{
	t_total deque;

// init 제대로 만들기 ft_calloc 사용
// 초기화 파싱
//	다 처리하고 나오는 것
//	알고리즘

	deque.a = malloc();

		if
	deque.b = malloc();
		if
	
	ft_numset1(&deque);
	printf("%d\n", deque.a.top->num);
	ft_numset2(&deque);
	printf("%d\n", deque.a.size);
	ft_numset3(&deque.a);
	printf("%d\n", deque.a.size);
}	

