/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:49:03 by seojo             #+#    #+#             */
/*   Updated: 2022/10/27 18:37:47 by seojo            ###   ########.fr       */
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
		if (av_num[i] < 1)
			return (1);
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

static void	init_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].info = info;
		pthread_mutex_init(&info->philo[i].m_eat, NULL);
		pthread_mutex_init(&info->philo[i].m_fork, NULL);
		info->philo[i].r_fork = &info->philo[i].fork;
		info->philo[i].l_fork = &info->philo[(i + 1) % info->num_philo].fork;
		info->philo[i].m_r_fork = &info->philo[i].m_fork;
		info->philo[i].m_l_fork = &info->philo[(i + 1) \
		% info->num_philo].m_fork;
		info->philo[i].tickat_num = i / 2;
	}
	info->philo[info->num_philo - 1].tickat_num = (info->num_philo >> 1) - 1;
}

int	init_info(t_info *info, char **av)
{
	int	i;

	if (init_av(info, av))
		return (printf("Wrong argument value\n"));
	info->philo = ft_calloc(info->num_philo, sizeof(t_philo));
	if (!info->philo)
		return (1);
	info->is_over = 0;
	info->is_ready = 0;
	info->tickat = malloc(sizeof(pthread_mutex_t) * info->num_philo >> 1);
	if (!info->tickat)
		return (printf("malloc error\n"));
	pthread_mutex_init(&info->m_ready, NULL);
	pthread_mutex_init(&info->m_over, NULL);
	pthread_mutex_init(&info->m_print, NULL);
	i = -1;
	while (++i < info->num_philo >> 1)
		pthread_mutex_init(&info->tickat[i], NULL);
	init_philo(info);
	return (0);
}
