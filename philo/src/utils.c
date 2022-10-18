/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:36:33 by seojo             #+#    #+#             */
/*   Updated: 2022/10/15 12:15:45 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	philo_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			return (ERROR);
		if (!ft_isdigit(str[i]))
			return (ERROR);
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		if ((num > 214748364 || (num == 214748364 && (str[i] > '7'))))
			return (-1);
		num = num * 10 + str[i++] - '0';
	}
	return (num);
}

int	print_usage(int exit_code)
{
	printf("Wrong argument! Please check usage.\n"\
			"Usage: ./philo [num_philos] [time_die] [time_eat]"\
			" [time_sleep] [num_each_philos_eat(optional)]\n");
	return (exit_code);
}

int	print_error(char *msg)
{
	while (*msg && msg)
		write(1, msg++, 1);
	write(1, "\n", 1);
	return (ERROR);
}

void	ft_free(void **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
