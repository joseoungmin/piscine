/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:24:13 by seojo             #+#    #+#             */
/*   Updated: 2022/10/10 13:48:48 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
/*
int	philo_atoi(const char *str)
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
*/
int	print_usage(int exit_code)
{
	printf("Wrong argument! Please check usage.\n"\
			"Usage: ./philo [num_philos] [time_die] [time_eat]"\
		" [time_sleep] [num_each_philos_eat(optional)]\n");
	return (exit_code);
}

void bye(void)
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	atexit(bye);

	int	num_of_philo;
	int	argv_num[6];
	int	i;

	if (ac < 5 || ac > 6)
		return (print_usage(1));
/*
	i = 1;
	while (i < ac)
	{
		argv_num[i] = philo_atoi(argv[i]);
		if (argv_num[i] == 0)
			return (printf_usage(1));
	}
*/

//	atoi

	return (0);
}
