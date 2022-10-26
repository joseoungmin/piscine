/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:35:50 by seojo             #+#    #+#             */
/*   Updated: 2022/10/26 12:10:40 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_all_done(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_lock(&philo[i].m_eat);
		if (philo[i].eat_cnt < philo->info->must_eat)
		{
			pthread_mutex_unlock(&philo[i].m_eat);
			return (FALSE);
		}
		pthread_mutex_unlock(&philo[i].m_eat);
		i++;
	}
	if (!philo->info->is_over)
	{
		print_done(philo);
		return (TRUE);
	}
	return (FALSE);
}

static int	check_dead(t_philo *philo)
{
	long long	starving;

	pthread_mutex_lock(&philo->m_eat);
	if (philo->eat_cnt != 0)
		starving = get_time_stamp(philo->last_eat);
	else
		starving = get_time_stamp(philo->info->start_time);
	pthread_mutex_unlock(&philo->m_eat);
	if (starving < philo->info->time_die)
		return (FALSE);
	else if (!philo->info->is_over)
	{
		print_die(philo);
		return (TRUE);
	}
	return (FALSE);
}

void	monitoring(t_info *info)
{
	int	i;
	int	is_dead;

	is_dead = FALSE;
	while (TRUE)
	{
		i = 0;
		while (i < info->num_philo && !is_dead)
			is_dead = check_dead(&info->philo[i++]);
		if (is_dead)
			break ;
		if (info->must_eat && check_all_done(info->philo))
			break ;
	}
}
