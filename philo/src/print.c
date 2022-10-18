/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:32:18 by seojo             #+#    #+#             */
/*   Updated: 2022/10/17 15:13:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void	ft_print_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_print);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		pthread_mutex_unlock(&philo->info->m_print);
		return ;
	}
	philo->info->is_over = TRUE;
	pthread_mutex_unlock(&philo->info->m_over);
	printf(COL_GREEN "Simulation stopped successfully!\n" COL_ORIGIN);
	pthread_mutex_unlock(&philo->info->m_print);
}

void	ft_print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_print);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		pthread_mutex_unlock(&philo->info->m_print);
		return ;
	}
	philo->info->is_over = TRUE;
	pthread_mutex_unlock(&philo->info->m_over);
	printf(COL_RED "%lldms\t%lld died\n" COL_ORIGIN, \
	ft_get_time_stamp(philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->info->m_print);
}

void	ft_print_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->info->m_print);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_over);
		pthread_mutex_unlock(&philo->info->m_print);
		if (state == EAT)
			pthread_mutex_unlock(&philo->m_eat);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_over);
	printf("%lld\t%lld ", ft_get_time_stamp(philo->info->start_time), \
	philo->id);
	if (state == FORK)
		printf("has taken a fork\n");
	else if (state == EAT)
		printf("is eating\n");
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	pthread_mutex_unlock(&philo->info->m_print);
}
