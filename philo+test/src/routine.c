/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2022/10/26 12:16:37 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	put_down_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->stat_r_fork = OFF;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	*philo->stat_l_fork = OFF;
	pthread_mutex_unlock(philo->l_fork);
	philo->has_fork = 0;
}

static int	ft_eat(t_philo *philo)
{
	if (philo->has_fork == 2)
	{
		pthread_mutex_lock(&philo->m_eat);
		print_state(philo, EAT);
		philo->last_eat = get_time_in_ms();
		philo->eat_cnt++;
		pthread_mutex_unlock(&philo->m_eat);
		ft_usleep(philo->info->time_eat);
		put_down_fork(philo);
		usleep(500);
		return (TRUE);
	}
	return (FALSE);
}

static void	sleep_and_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	print_state(philo, SLEEP);
	ft_usleep(philo->info->time_sleep);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	print_state(philo, THINK);
	if (philo->info->num_philo & 0x1)
		usleep(100);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info->m_ready);
	pthread_mutex_unlock(&philo->info->m_ready);
	if (philo->info->is_ready == ERROR)
		return (NULL);
	if (!(philo->id & 0x1))
		ft_usleep(philo->info->time_eat);
	while (TRUE)
	{
		take_forks(philo);
		if (ft_eat(philo))
			sleep_and_think(philo);
		pthread_mutex_lock(&philo->info->m_over);
		if (philo->info->is_over)
			break ;
		pthread_mutex_unlock(&philo->info->m_over);
	}
	pthread_mutex_unlock(&philo->info->m_over);
	return (NULL);
}
