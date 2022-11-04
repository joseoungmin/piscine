/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2022/11/04 15:28:48 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_eat(t_philo *philo)
{
	sem_wait(philo->info->sm_fork);
	print_state(philo, FORK);
	sem_wait(philo->info->sm_fork);
	print_state(philo, FORK);
	sem_wait(philo->sm_eat);
	print_state(philo, EAT);
	philo->last_eat = get_time_in_ms();
	philo->eat_cnt += 1;
	if (philo->eat_cnt == philo->info->must_eat)
		sem_post(philo->info->sm_done);
	sem_post(philo->sm_eat);
	ft_usleep(philo->info->time_eat);
	sem_post(philo->info->sm_fork);
	sem_post(philo->info->sm_fork);
}

static void	sleep_and_think(t_philo *philo)
{
	print_state(philo, SLEEP);
	ft_usleep(philo->info->time_sleep);
	print_state(philo, THINK);
}

void	philo_routine(t_philo *philo)
{
	sem_wait(philo->info->sm_start);
	sem_post(philo->info->sm_start);
	monitoring_philo(philo);
	while (1)
	{
		ft_eat(philo);
		sleep_and_think(philo);
	}
}
