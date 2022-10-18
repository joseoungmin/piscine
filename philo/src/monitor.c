/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:20:49 by seojo             #+#    #+#             */
/*   Updated: 2022/10/17 14:41:56 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


static int	ft_check_all_done(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo->info;
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_lock(&philo[i].m_eat);
		if (philo[i].meal_cnt < info->must_eat)
		{
			pthread_mutex_unlock(&philo[i].m_eat);
			return (FALSE);
		}
		pthread_mutex_unlock(&philo[i].m_eat);
		i++;
	}
	if (!info->is_over)
	{
		ft_print_done(philo);
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_check_dead(t_philo *philo)
{
	t_info			*info;
	uint64_t		starving;

	info = philo->info;
	pthread_mutex_lock(&philo->m_eat);
	if (philo->meal_cnt != 0)
		starving = ft_get_time_stamp(philo->last_meal);
	else
		starving = ft_get_time_stamp(info->start_time);
	pthread_mutex_unlock(&philo->m_eat);
	if (starving < info->time_die)
		return (FALSE);
	else if (!info->is_over)
	{
		ft_print_die(philo);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_monitoring(t_info *info)
{
	int	i;
	int	is_dead;

	is_dead = FALSE;
	while (TRUE)
	{
		i = 0;
		while ((i < info->num_philo) && (!is_dead))
			is_dead = ft_check_dead(&info->philo[i++]);
		if (is_dead)
			break ;
		if (info->must_eat && ft_check_all_done(info->philo))
			break ;
	}
}
