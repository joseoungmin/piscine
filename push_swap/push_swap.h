/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:10:03 by seojo             #+#    #+#             */
/*   Updated: 2022/09/27 19:54:23 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*perv;
	struct s_node	*next;
}					t_node;

typedef struct s_deque
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}			t_deque;

typedef struct s_total
{
	t_deque	*a;
	t_deque	*b;
}			t_total;

void	test_deque_print(t_total *deque, char *msg);
void	test_deque(t_total *deque);


void	free_dptr(char **str);
int		ft_check_num(char *str);
int		ft_check_dup(t_node *head, int num);
void	ft_error(int errnum);
int		ft_pu_atoi(const char *str);
t_node	*ft_nodenew(int content);
void	ft_lstadd_next(t_deque **a, t_node *new);
void	ft_check_sort(t_node *head);
void	av_parse(char **av, t_deque *a, int i, int atoint);
void	total_init(t_total *total);
int		ft_swap(t_deque *stack);
int		ft_sa(t_total *total);
int		ft_sb(t_total *total);
int		ft_ss(t_total *total);
int		ft_pb(t_total *total);
int		ft_pa(t_total *total);
int		ft_ra(t_total *total);
int		ft_rb(t_total *total);
int		ft_rr(t_total *total);
int		ft_rra(t_total *total);
int		ft_rrb(t_total *total);
int		ft_rrr(t_total *total);
void	ft_sort_three(t_total *total);

#endif
