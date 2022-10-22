/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2022/10/22 12:09:36 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	a_philo;

	a_philo = (t_philo *)arg;
	pthread_mutex_lock(&a_philo->info->m_ready);
	pthread_mutex_unlock(&a_philo->info->m_ready);
	if (a_philo->info->is_ready == ERROR)
		return (NULL);
	if (!(a_philo->id & 0x1))
		ft_usleep(a_philo->info->time_eat);
	while (1)
	{
		take_forks(a_philo);
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
