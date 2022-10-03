/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 11:09:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_total	total;

	if (ac == 1)
		return (0);
	total_init(&total);
	av_parse(av, total.a, 0, 0);
	if (total.a->size == 2)
		ft_sa(&total);
	if (total.a->size == 3)
		ft_sort_three(&total);
	else
		ft_sort(&total);
}
