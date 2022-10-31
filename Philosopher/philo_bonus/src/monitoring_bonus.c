/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:35:50 by seojo             #+#    #+#             */
/*   Updated: 2022/10/30 13:34:42 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_dead(t_philo *philo)
{
	long long	starving;

	if (philo->eat_cnt == 0)
		starving = get_time_stamp(philo->info->start_time);
	else
		starving = get_time_stamp(philo->last_eat);
	if (starving >= philo->info->time_die && !philo->info->is_dead)
	{
		print_die(philo);
		sem_post(philo->info->sm_dead);
		return (1);
	}
	return (0);
}

static void	*over_if_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->sm_eat);
		philo->info->is_dead = check_dead(philo);
		sem_post(philo->sm_eat);
		usleep(500);
	}
	return (NULL);
}

void	monitoring_philo(t_philo *philo)
{
	if (pthread_create(&philo->tid, NULL, \
	over_if_dead, (void *) philo))
		error_stop(philo->info, "pthread_create error");
}

static void	*check_done(void *arg)
{
	long long	i;
	t_info		*info;

	info = (t_info *)arg;
	i = -1;
	while (++i < info->num_philo)
		sem_wait(info->sm_done);
	if (!info->is_dead)
	{
		print_done(info->philo);
		sem_post(info->sm_dead);
	}
	return (NULL);
}

void	monitoring_parent(t_info *info)
{
	pthread_t	tid;
	long long	i;

	if (pthread_create(&tid, NULL, check_done, (void *)info))
		print_error("pthread_create error");
	sem_wait(info->sm_dead);
	term_all_process(info);
	info->is_dead = TRUE;
	i = -1;
	while (++i < info->num_philo)
		sem_post(info->sm_done);
	pthread_join(tid, NULL);
}
