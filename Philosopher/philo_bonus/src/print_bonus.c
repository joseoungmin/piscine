/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:54:09 by seojo             #+#    #+#             */
/*   Updated: 2022/10/30 02:32:56 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_done(t_philo *philo)
{
	sem_wait(philo->info->sm_print);
	printf(COL_GREEN "Simulation stopped successfully!\n" COL_ORIGIN);
}

void	print_die(t_philo *philo)
{
	sem_wait(philo->info->sm_print);
	printf(COL_RED "%lldms\t%d died\n" COL_ORIGIN, \
			get_time_stamp(philo->info->start_time), philo->id);
}

void	print_state(t_philo *philo, int state)
{
	sem_wait(philo->info->sm_print);
	printf("%lld\t%d ", get_time_stamp(philo->info->start_time), philo->id);
	if (state == FORK)
		printf("has taken a fork\n");
	else if (state == EAT)
		printf("is eating\n");
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	sem_post(philo->info->sm_print);
}
