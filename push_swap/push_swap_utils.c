/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:36:32 by seojo             #+#    #+#             */
/*   Updated: 2022/09/21 21:14:36 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dptr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

int	ft_check_num(char *str)
{
	while(*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		str++;
	}
	while('0' <= *str && *str <= '9')
		str++;
	if (!*str)
		return (1);
	return (0);
}

int	ft_check_dup(t_node *head, int num)
{
	t_node *point;

	point = head;
	while (point)
	{
		if (point->num == num)
			return (1);
		point = point->next;
	}
	return (0);
}

void	ft_error(int errnum)
{
	write(1, "Error\n", 6);
	exit(errnum);
}
