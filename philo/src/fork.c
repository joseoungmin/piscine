/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:47:20 by seojo             #+#    #+#             */
/*   Updated: 2022/10/17 14:16:35 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_right_fork(t_philo *a_philo)
{
	pthread_mutex_lock(&a_philo->info->m_over);
	if (a_philo->info->is_over)
	{
		pthread_mutex_unlock(&a_philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&a_philo->info->m_over);
	pthread_mutex_lock(a_philo->r_fork);
	if (*a_philo->stat_r_fork == OFF)
	{
		*a_philo->stat_r_fork = ON;
		a_philo->has_r_fork = ON;
		ft_print_state(a_philo, FORK);
	}
	pthread_mutex_unlock(a_philo->r_fork);
}

static void	take_left_fork(t_philo *a_philo)
{
	pthread_mutex_lock(&a_philo->info->m_over);
	if (a_philo->info->is_over)
	{
		pthread_mutex_unlock(&a_philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&a_philo->info->m_over);
	if (a_philo->info->num_philo == 1 && a_philo->id == 1)
	{
		pthread_mutex_unlock(a_philo->r_fork);
		ft_usleep(a_philo->info->time_die);
	}
	else
	{
		pthread_mutex_lock(a_philo->l_fork);
		if (*a_philo->stat_l_fork == OFF)
		{
			*a_philo->stat_l_fork = ON;
			a_philo->has_l_fork = ON;
			ft_print_state(a_philo, FORK);
		}
		pthread_mutex_unlock(a_philo->l_fork);
	}
}

void	ft_take_forks(t_philo *a_philo)
{
	if (a_philo->id & 0x1)
	{
		take_right_fork(a_philo);
		take_left_fork(a_philo);
	}
	else
	{
		take_left_fork(a_philo);
		take_right_fork(a_philo);
	}
}
