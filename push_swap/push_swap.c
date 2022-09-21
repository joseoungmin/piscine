/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/09/22 00:06:05 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>
//top 에 넣고빼고
//bottom 에 넣고빼고

//노드 하나씩 돌리고 
//노드의 넥스트는 노드
int main(int ac, char **av)
{
    t_total	total;

    if (ac == 1)
        return (0);
	total_init(&total);
	av_parse(av, total.a, 0, 0);

	


//여기는 출력
	t_node *tmp;
	tmp = total.a->top;
	printf("a_stack\n");
    while (tmp)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
    }
	printf("a_deque.size = %d\n", total.a->size);
}
