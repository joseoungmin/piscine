/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 14:36:15 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_cmd_cmp(t_total *total, char *tmp)
{
	if (!ft_strncmp(tmp, "sa\n", 3))
		ft_sa(total);
	else if (!ft_strncmp(tmp, "sb\n", 3))
		ft_sb(total);
	else if (!ft_strncmp(tmp, "ss\n", 3))
		ft_ss(total);
	else if (!ft_strncmp(tmp, "pa\n", 3))
		ft_pa(total);
	else if (!ft_strncmp(tmp, "pb\n", 3))
		ft_pb(total);
	else if (!ft_strncmp(tmp, "ra\n", 3))
		ft_ra(total);
	else if (!ft_strncmp(tmp, "rr\n", 3))
		ft_rr(total);
	else if (!ft_strncmp(tmp, "rra\n", 4))
		ft_rra(total);
	else if (!ft_strncmp(tmp, "rrb\n", 4))
		ft_rrb(total);
	else if (!ft_strncmp(tmp, "rrr\n", 4))
		ft_rrr(total);
	else
		ft_error(1);
}

void	ft_cmd_check(t_total *total)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		ft_cmd_cmp(total, tmp);
		free(tmp);
		tmp = get_next_line(0);
	}
}

int	ft_is_sort(t_total *total)
{
	int		max;
	t_node	*tmp;

	max = -2147483648;
	tmp = total->a->top;
	while (tmp)
	{
		if (max > tmp->num)
			return (0);
		max = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_total	total;

	if (ac == 1)
		return (0);
	total_init(&total);
	av_parse(av, total.a, 0, 0);
	ft_cmd_check(&total);
	if (total.b->size == 0 && ft_is_sort(&total))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
