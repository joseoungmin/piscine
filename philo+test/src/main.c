/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/18 20:26:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_usage(int exit_code)
{
	printf("Wrong argument!\nusage: ./philo number_of_philos time_to_die" 
			" time_to_eat time_to_sleep [philo_must_eat]\n");
	return (exit_code);
}

long long	ft_atoll(const char *str)
{
	const long long max = LLONG_MAX;
	long long		num;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			return (ERROR);
	while (*str && *str >= '0' && *str <= '9')
	{
		if (num > max / 10 || (num == max / 10 && *str - '0' > max % 10))
			return (ERROR);
		num = num * 10 + *str++ - '0';
	}
	return (num);
}

int init_av(t_info *info, char **av)
{
	long long 	av_num[6];
	int			i;

	i = 0;
	while (av[++i])
	{
		av_num = ft_atoll(av[i]);
		if (ab_num == ERROR)
			return (1);
	}
	info->num_philo = av_num[1];
	info->time_die = av_num[2];
	info->time_eat = av_num[3];
	info->time_sleep = av_num[4];
	if (av[5])
		info->must_eat = av_num[5];
	else
		into->must_eat = 0;
	return (0);
}

int	init_info(t_info *info, char **av)
{
	if (init_av(info, av))
		return (1);
	info->philo = ft_calloc(info->num_philo, sizeof(t_philo));
	if (!info->philo)
		return (1);

	return (0);
}

int main(int ac, char **av)
{
	t_info	info;
	
	if (ac < 5 || 6 < ac)
		return (print_usage(1));
	if (init_info(&info, av))
		return (1);

	return (0);
}
