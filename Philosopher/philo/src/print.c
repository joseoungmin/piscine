/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:54:09 by seojo             #+#    #+#             */
/*   Updated: 2022/10/25 12:07:51 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_print);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_print);
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	philo->info->is_over = TRUE;
	pthread_mutex_unlock(&philo->info->m_over);
	printf(COL_GREEN "Simulation stopped successfully!\n" COL_ORIGIN);
	pthread_mutex_unlock(&philo->info->m_print);
}

void	print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_print);
	pthread_mutex_lock(&philo->info->m_over);
	if (philo->info->is_over)
	{
		pthread_mutex_unlock(&philo->info->m_print);
		pthread_mutex_unlock(&philo->info->m_over);
		return ;
	}
	philo->info->is_over = TRUE;
	pthread_mutex_unlock(&philo->info->m_over);
	printf(COL_RED "%lldms\t%d died\n" COL_ORIGIN, \
			get_time_stamp(philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->info->m_print);
}

void	print_state(t_philo *philo, int state)
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
	printf("%lld\t%d ", get_time_stamp(philo->info->start_time), philo->id);
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
