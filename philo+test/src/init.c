/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:49:03 by seojo             #+#    #+#             */
/*   Updated: 2022/10/25 19:38:54 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_av(t_info *info, char **av)
{
	long long	av_num[6];
	int			i;

	i = 0;
	while (av[++i])
	{
		av_num[i] = ft_atolld(av[i]);
		if (av_num[i] == ERROR)
			return (print_error("error: Wrong arument!"));
	}
	info->num_philo = av_num[1];
	info->time_die = av_num[2];
	info->time_eat = av_num[3];
	info->time_sleep = av_num[4];
	if (av[5])
		info->must_eat = av_num[5];
	else
		info->must_eat = 0;
	return (0);
}

static void	init_fork(t_info *info, int i)
{
	t_philo	*philo;

	philo = info->philo;
	philo[i].id = i + 1;
	philo[i].info = info;
	pthread_mutex_init(&philo[i].m_eat, NULL);
	pthread_mutex_init(&philo[i].fork, NULL);
	philo[i].r_fork = &philo[i].fork;
}

static void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	init_fork(info, i);
	info->philo[i].l_fork = &info->philo[info->num_philo - 1].fork;
	info->philo[i].stat_l_fork = &info->philo[info->num_philo - 1].stat_r_fork;
	while (++i < info->num_philo)
	{
		init_fork(info, i);
		info->philo[i].l_fork = &info->philo[i - 1].fork;
		info->philo[i].stat_l_fork = &info->philo[i - 1].stat_r_fork;
	}
}

int	init_info(t_info *info, char **av)
{
	if (init_av(info, av))
		return (printf("Wrong argument value\n"));
	info->philo = ft_calloc(info->num_philo, sizeof(t_philo));
	if (!info->philo)
		return (1);
	info->is_over = 0;
	info->is_ready = 0;
	pthread_mutex_init(&info->m_ready, NULL);
	pthread_mutex_init(&info->m_over, NULL);
	pthread_mutex_init(&info->m_print, NULL);
	init_philo(info);
	return (0);
}
