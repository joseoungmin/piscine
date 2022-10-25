/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:24:13 by seojo             #+#    #+#             */
/*   Updated: 2022/10/23 21:22:07 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_put_down_fork(t_philo *a_philo)
{
	pthread_mutex_lock(a_philo->r_fork);
	*a_philo->stat_r_fork = OFF;
	a_philo->has_r_fork = OFF;
	pthread_mutex_unlock(a_philo->r_fork);
	pthread_mutex_lock(a_philo->l_fork);
	*a_philo->stat_l_fork = OFF;
	a_philo->has_l_fork = OFF;
	pthread_mutex_unlock(a_philo->l_fork);
	//pthread_mutex_lock(&a_philo->info->m_over);
}

static int	ft_is_valid_to_eat(t_philo *a_philo)
{
	int	ret;

	ret = 1;
	pthread_mutex_lock(a_philo->r_fork);
	ret *= a_philo->has_r_fork;
	pthread_mutex_unlock(a_philo->r_fork);
	pthread_mutex_lock(a_philo->l_fork);
	ret *= a_philo->has_l_fork;
	pthread_mutex_unlock(a_philo->l_fork);
	return (ret);
}

static int	ft_eat(t_philo *a_philo)
{
	if (ft_is_valid_to_eat(a_philo))
	{
		pthread_mutex_lock(&a_philo->m_eat);
		ft_print_state(a_philo, EAT);
		a_philo->last_meal = ft_get_time_in_ms();
		a_philo->meal_cnt++;
		pthread_mutex_unlock(&a_philo->m_eat);
		ft_usleep(a_philo->info->time_eat);
		ft_put_down_fork(a_philo);
		return (TRUE);
	}
	return (FALSE);
}

static void	ft_sleep_and_think(t_philo *a_philo)
{
	pthread_mutex_lock(&a_philo->info->m_over);
	if (a_philo->info->is_over)
	{
		pthread_mutex_unlock(&a_philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&a_philo->info->m_over);
	ft_print_state(a_philo, SLEEP);
	ft_usleep(a_philo->info->time_sleep);
	pthread_mutex_lock(&a_philo->info->m_over);
	if (a_philo->info->is_over)
	{
		pthread_mutex_unlock(&a_philo->info->m_over);
		return ;
	}
	pthread_mutex_unlock(&a_philo->info->m_over);
	ft_print_state(a_philo, THINK);
	if (a_philo->info->num_philo & 0x1)
		usleep(100);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*a_philo;

	a_philo = (t_philo *)arg;
	pthread_mutex_lock(&a_philo->info->m_ready);
	pthread_mutex_unlock(&a_philo->info->m_ready);
	if (a_philo->info->is_ready == ERROR)
		return (NULL);
	if (!(a_philo->id & 0x1))
		ft_usleep(a_philo->info->time_eat);
	while (TRUE)
	{
		ft_take_forks(a_philo);
		if (ft_eat(a_philo))
			ft_sleep_and_think(a_philo);
		pthread_mutex_lock(&a_philo->info->m_over);
		if (a_philo->info->is_over)
			break ;
		pthread_mutex_unlock(&a_philo->info->m_over);
	}
	pthread_mutex_unlock(&a_philo->info->m_over);
	return (NULL);
}
