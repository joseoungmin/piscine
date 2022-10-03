/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:36:32 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 14:15:01 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	while (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		str++;
	}
	while ('0' <= *str && *str <= '9')
		str++;
	if (!*str)
		return (1);
	return (0);
}

int	ft_check_dup(t_node *head, int num)
{
	t_node	*point;

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
		if ((num > 214748364 || (num == 214748364 && \
						(str[i] > '7' + (sign == -1)))))
			ft_error(0);
		num = num * 10 + str[i++] - '0';
	}
	return (num * sign);
}
