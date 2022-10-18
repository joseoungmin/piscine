/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:35:54 by seojo             #+#    #+#             */
/*   Updated: 2022/10/15 10:13:25 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	set_fork_position(t_philo *philo, int i, int all)
{
	philo[i].r_fork = &philo[i].fork;
	philo[i].stat_r_fork = &philo[i].stat_fork;
	if (i == 0)
	{
		philo[i].l_fork = &philo[all - 1].fork;
		philo[i].stat_l_fork = &philo[all - 1].stat_fork;
	}
	else
	{
		philo[i].stat_l_fork = &philo[i - 1].stat_fork;
		philo[i].l_fork = &philo[i - 1].fork;
	}
}

static void	init_philo(t_info *info, t_philo *philo)
{
	int	i;
	int	philo_cnt;

	i = 0;
	philo_cnt = info->num_philo;
	while (i < philo_cnt)
	{
		philo[i].id = i + 1;
		philo[i].info = info;
		philo[i].meal_cnt = 0;
		philo[i].stat_fork = OFF;
		philo[i].has_r_fork = OFF;
		philo[i].has_l_fork = OFF;
		pthread_mutex_init(&philo[i].m_eat, NULL);
		pthread_mutex_init(&philo[i].fork, NULL);
		set_fork_position(philo, i, philo_cnt);
		i++;
	}
}

static int	init_info_av(t_info *info, char **av)
{
	int	av_num[6];
	int i;

	i = 0;
	while (av[++i])
	{
		av_num[i] = philo_atoi(av[i]);
		if (av_num[i] == ERROR)
			return (print_usage(ERROR));
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

int	init_info(t_info *info, char **av)
{
	t_philo *philo;

	if (init_info_av(info, av) == ERROR)
		return (ERROR);
	philo = malloc(sizeof(t_philo *) * (info->num_philo));
	if(!philo)
		return (ERROR);
	info->philo = philo;
	info->is_over = FALSE;
	info->is_ready = FALSE;
	pthread_mutex_init(&info->m_ready, NULL);
	pthread_mutex_init(&info->m_over, NULL);
	pthread_mutex_init(&info->m_print, NULL);
	init_philo(info, philo);
	return (0);
}
