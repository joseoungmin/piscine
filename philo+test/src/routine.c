/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2022/10/23 21:35:32 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	pthread_mutex_lock(philo->r_fork);
	if (*philo->stat_l_fork == OFF)
	{
		*philo->stat_l_fork = ON;
		philo->has_fork += 1;
		print_state(philo, FORK);
	}
	pthread_mutex_unlock(philo->l_fork);
}

static void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	if (philo->info->num_philo == 1 && philo->id == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		ft_usleep(philo->info->time_die);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		if (philo->stat_r_fork == OFF)
		{
			philo->stat_r_fork = ON;
			philo->has_fork += 1;
			print_state(philo, FORK);
		}
		pthread_mutex_unlock(philo->r_fork);
	}
}

void	take_forks(t_philo *philo)
{
	if (philo->id & 0x1)
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
	else
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
}

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
		return (1);
	}
	return (0);
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
	while (1)
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
