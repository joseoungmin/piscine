/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:10:03 by seojo             #+#    #+#             */
/*   Updated: 2022/09/21 15:20:45 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_dlst
{
    int     num;
    struct s_lst *perv;
    struct s_lst *next;
}   t_dlst;

typedef	struct s_deque
{
	int		size;
	t_dlst 	*top;
	t_dlst 	*bottom;
}			t_deque;

typedef struct s_total
{
	t_deque	*a;
	t_deque	*b;
}			t_total;

void	test_deque_print(t_total *deque, char *msg);
void	test_deque(t_total deque);

#endif
