/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2022/10/22 15:37:05 by seojo            ###   ########.fr       */
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
		philo->eat_ready++;
		ft_print_state(philo, FORK);
	}
	pthread_mutex_unlock(philo->l_fork);
}

static void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_over);
	if (a_philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	if (philo->info->num_philo == 1 && philo->id == 1)
	{
		pthread_mutex_unlock(a_philo->r_fork);
		ft_usleep(a_philo->info->time->die);
	}
	else
	{
		pthread_mutex_lock(&philo->r_fork);
		if (philo->stat_r_fork == OFF)
		{
			philo->stat_r_fork = ON;
			philo->eat_ready++;
			ft_print_state(philo, FORK);
		}
		pthread_mutex_unlock(&philo->r_fork);
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
	philo->eat_ready = 0;
}

static int	ft_eat(t_philo *philo)
{
	if (philo->eat_ready == 2)
	{
		pthread_mutex_lock(&philo->m_eat);
		ft_print_state(philo, EAT);
		philo->eat_cnt++;
		pthread_mutex_unlock(&philo->m_eat);
		ft_usleep(philo->info->eat_time);
		put_down_fork(philo);
		return (1);
	}
	return (0);
}

static void	sleep_and_think(t_philo *philo)
{
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info);
		return ;
	}
	pthread_mutex_unlock(&philo->info);
	print_state(philo, SLEEP);
	ft_usleep(philo->info->time_sleep);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(

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
			ft_sleep_and_think(philo);
		pthread_mutex_lock(&philo->info->m_over);
		if (philo->info->is_over)
			break ;
		pthread_mutex_unlock(&philo->info->m_over);
	}
	pthread_mutex_unlock(&philo->info->m_over);
	return (NULL);
}
