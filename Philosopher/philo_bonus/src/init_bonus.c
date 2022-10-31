/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:49:03 by seojo             #+#    #+#             */
/*   Updated: 2022/10/30 13:56:26 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

static void	init_sem(t_info *info)
{
	sem_unlink("sm_start");
	info->sm_start = sem_open("sm_start", O_CREAT, 0644, 1);
	sem_unlink("sm_print");
	info->sm_print = sem_open("sm_print", O_CREAT, 0644, 1);
	sem_unlink("sm_fork");
	info->sm_fork = sem_open("sm_fork", O_CREAT, 0644, info->num_philo);
	sem_unlink("sm_set_eat");
	info->sm_set_eat = sem_open("sm_set_eat", O_CREAT, 0644, info->num_philo / 2);
	sem_unlink("sm_dead");
	info->sm_dead = sem_open("sm_dead", O_CREAT, 0644, 0);
	sem_unlink("sm_done");
	info->sm_done = sem_open("sm_done", O_CREAT, 0644, 0);
}

int	init_info(t_info *info, char **av)
{
	int	i;

	if (init_av(info, av))
		return (printf("Wrong argument value\n"));
	info->philo = ft_calloc(info->num_philo, sizeof(t_philo));
	if (!info->philo)
		return (printf("malloc error\n"));
	info->is_dead = FALSE;
	init_sem(info);
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].info = info;
		sem_unlink("sm_eat");
		info->philo[i].sm_eat = sem_open("sm_eat", O_CREAT, 0644, 1);
	}
	if (info->num_philo == 1)
		sem_post(info->sm_set_eat);
	return (0);
}
