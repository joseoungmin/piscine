/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2022/10/27 18:19:00 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->tickat_num != -1)
	{
		pthread_mutex_lock(philo->m_r_fork);
		if (*philo->r_fork == OFF)
		{
			*philo->r_fork = ON;
			print_state(philo, FORK);
		}
		pthread_mutex_unlock(philo->m_r_fork);
		pthread_mutex_lock(philo->m_l_fork);
		if (*philo->l_fork == OFF)
		{
			*philo->l_fork = ON;
			print_state(philo, FORK);
		}
		pthread_mutex_unlock(philo->m_l_fork);
	}
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

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->tickat[philo->tickat_num]);
	pthread_mutex_lock(&philo->m_eat);
	take_forks(philo);
	print_state(philo, EAT);
	philo->last_eat = get_time_in_ms();
	pthread_mutex_unlock(&philo->m_eat);
	ft_usleep(philo->info->time_eat);
	pthread_mutex_lock(&philo->m_eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->m_eat);
	pthread_mutex_lock(philo->m_r_fork);
	pthread_mutex_lock(philo->m_l_fork);
	*philo->r_fork = OFF;
	*philo->l_fork = OFF;
	pthread_mutex_unlock(philo->m_l_fork);
	pthread_mutex_unlock(philo->m_r_fork);
	pthread_mutex_unlock(&philo->info->tickat[philo->tickat_num]);
	usleep(500);
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
		usleep(100);
	if (philo->info->num_philo == 1 && philo->id == 1)
		return (NULL);
	while (TRUE)
	{
		if (philo->tickat_num == -1)
			philo->tickat_num = (philo->info->num_philo >> 1) - 1;
		ft_eat(philo);
		sleep_and_think(philo);
		philo->tickat_num--;
		pthread_mutex_lock(&philo->info->m_over);
		if (philo->info->is_over)
			break ;
		pthread_mutex_unlock(&philo->info->m_over);
	}
	pthread_mutex_unlock(&philo->info->m_over);
	return (NULL);
}
