/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:58:54 by seojo             #+#    #+#             */
/*   Updated: 2022/10/27 17:11:44 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	stop_simulating(t_info *info, long long end)
{
	long long	i;

	i = -1;
	while (++i < end)
		pthread_join(info->philo[i].tid, NULL);
	i = -1;
	while (++i < end)
	{
		pthread_mutex_destroy(&info->philo[i].m_fork);
		pthread_mutex_destroy(&info->philo[i].m_eat);
	}
	pthread_mutex_destroy(&info->m_ready);
	pthread_mutex_destroy(&info->m_print);
	pthread_mutex_destroy(&info->m_over);
	ft_free((void **) &info->philo);
}

static int	error_stop(t_info *info, long long i, char *msg)
{
	print_error(msg);
	if (i > 0)
		stop_simulating(info, i - 1);
	return (1);
}

int	simulate(t_info *info)
{
	long long	i;

	i = 0;
	pthread_mutex_lock(&info->m_ready);
	while (i < info->num_philo)
	{
		if (pthread_create(&info->philo[i].tid, NULL, \
			philo_routine, (void *)&info->philo[i]))
		{
			info->is_ready = ERROR;
			pthread_mutex_unlock(&info->m_ready);
			return (error_stop(info, i, "error: thread_create"));
		}
		i++;
	}
	info->start_time = get_time_in_ms();
	pthread_mutex_unlock(&info->m_ready);
	monitoring(info);
	stop_simulating(info, i);
	return (0);
}
