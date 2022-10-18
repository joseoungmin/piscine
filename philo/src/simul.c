/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:05:34 by seojo             #+#    #+#             */
/*   Updated: 2022/10/17 15:05:40 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	stop_simulating(t_info *info, unsigned int idx_end)
{
	unsigned int	i;

	i = -1;
	while (++i < idx_end)
		pthread_join(info->philo[i].tid, NULL);
	i = -1;
	while (++i < idx_end)
	{
		pthread_mutex_destroy(&info->philo[i].fork);
		pthread_mutex_destroy(&info->philo[i].m_eat);
	}
	pthread_mutex_destroy(&info->m_ready);
	pthread_mutex_destroy(&info->m_print);
	pthread_mutex_destroy(&info->m_over);
	ft_free((void **) &info->philo);
}

static int	stop_by_error(t_info *info, unsigned int idx_end, char *err_msg)
{
	print_error(err_msg);
	if (idx_end > 0)
		stop_simulating(info, idx_end - 1);
	return (ERROR);
}

int	ft_simulate(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->m_ready);
	while (i < info->num_philo)
	{
		if (pthread_create(&info->philo[i].tid, NULL, \
		ft_philo_routine, (void *) &info->philo[i]))
		{
			info->is_ready = ERROR;
			pthread_mutex_unlock(&info->m_ready);
			return (stop_by_error(info, i, "error: pthread_create"));
		}
		i++;
	}
	info->start_time = ft_get_time_in_ms();
	pthread_mutex_unlock(&info->m_ready);
	ft_monitoring(info);
	stop_simulating(info, i);
	return (0);
}
