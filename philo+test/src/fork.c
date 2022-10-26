/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:04:19 by seojo             #+#    #+#             */
/*   Updated: 2022/10/26 12:20:13 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_right_fork(t_philo *philo)
{
	/*pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	*/
	pthread_mutex_lock(philo->r_fork);
	if (philo->stat_r_fork == OFF)
	{
		philo->stat_r_fork = ON;
		philo->has_fork += 1;
		print_state(philo, FORK);
	}
	pthread_mutex_unlock(philo->r_fork);
}

static void	take_left_fork(t_philo *philo)
{
	/*
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	*/
	if (philo->info->num_philo == 1 && philo->id == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		ft_usleep(philo->info->time_die);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		if (*philo->stat_l_fork == OFF)
		{
			*philo->stat_l_fork = ON;
			philo->has_fork += 1;
			print_state(philo, FORK);
		}
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	take_forks(t_philo *philo)
{
	if (philo->id & 0x1)
	{
		take_right_fork(philo);
		pthread_mutex_lock(&philo->info->m_over);
		if (philo->info->is_over)
		{
			pthread_mutex_unlock(&philo->info->m_over);
			return ;
		}
		pthread_mutex_unlock(&philo->info->m_over);
		take_left_fork(philo);
	}
	else
	{
		take_left_fork(philo);
		pthread_mutex_lock(&philo->info->m_over);
		if (philo->info->is_over)
		{
			pthread_mutex_unlock(&philo->info->m_over);
			return ;
		}
		pthread_mutex_unlock(&philo->info->m_over);
		take_right_fork(philo);
	}
}
