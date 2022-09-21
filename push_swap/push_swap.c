/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/09/21 21:09:24 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



#include <stdio.h>
//top 에 넣고빼고
//bottom 에 넣고빼고

//노드 하나씩 돌리고 
//노드의 넥스트는 노드

int	ft_pu_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		if (!ft_isdigit(str[i]))
			ft_error(0);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((num > 214748364 || (num == 214748364 && (str[i] > '7' + (sign == -1)))))
			ft_error(0);
		num = num * 10 + str[i++] - '0';
	}
	return (num * sign);
}

t_node	*ft_nodenew(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
    new->perv = NULL;
	return (new);
}

void	ft_lstadd_next(t_deque **a, t_node *new)
{
	if (!(*a) || !new)
		return ;
	if (!((*a)->top))
	{
		(*a)->bottom = new;
		(*a)->top = new;
		(*a)->size = 1;
	}
	else
	{
		(*a)->bottom->next = new;
        new->perv = (*a)->bottom;
		(*a)->bottom = new;
		(*a)->size += 1;
	}
}

void	ft_check_sort(t_node *head)
{
	t_node	*point;

	point = head;
	while (point && point->next)
	{
		printf("point_num = %d\n", point->num);
		if (point->num > point->next->num)
			return ;
		point = point->next;
	}
	if (!point)
		exit(0);
}

void	av_parse(char **av, t_deque *a, int i, int atoint)
{
	char	**buf;
	int		j;
	int		k;

	if (!a || !av)
		ft_error(0);
    while(av[++i])
    {
        j = -1;
        buf = ft_split(av[i], ' ');
		if (!buf)
			ft_error(1);
		if (buf && !*buf)
			ft_error(2);
        while (buf[++j])
        {
            k = -1;
			atoint = ft_pu_atoi(buf[j]);
			if (!ft_check_num(buf[j]) || ft_check_dup(a->top, atoint))
				ft_error(0);
			//ft_check_sort(a->top);
        	ft_lstadd_next(&a, ft_nodenew(atoint));
        }
		free_dptr(buf);
    }
}

void	total_init(t_total *total)
{

	total->a = ft_calloc(1, sizeof(t_deque));
	if (!total->a)
		ft_error(0);
	total->b = ft_calloc(1, sizeof(t_deque));
	if (!total->b)
		ft_error(0);
}

int main(int ac, char **av)
{
    t_total	total;
	t_node *tmp;

    if (ac == 1)
        return (0);
	total_init(&total);
	av_parse(av, total.a, 0, 0);
	
	tmp = total.a->top;
    while (tmp)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
    }
	printf("a_deque.size = %d\n", total.a->size);
}
