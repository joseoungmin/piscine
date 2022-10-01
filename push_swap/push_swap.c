/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/10/01 16:06:18 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>


int main(int ac, char **av)
{
    t_total	total;

    if (ac == 1)
        return (0);
	total_init(&total);
	av_parse(av, total.a, 0, 0);

	//test
	test_deque(&total);
	test_deque_print(&total, "test");

	//pivot and quick sort
}
