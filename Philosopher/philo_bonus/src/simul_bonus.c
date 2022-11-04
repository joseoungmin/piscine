/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:58:54 by seojo             #+#    #+#             */
/*   Updated: 2022/11/04 15:31:51 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	term_all_process(t_info *info)
{
	long long	i;

	i = -1;
	while (++i < info->num_philo)
		if (info->philo[i].pid > 0)
			kill(info->philo[i].pid, SIGTERM);
}

void	ft_free_info_sem(t_info *info)
{
	sem_unlink("sm_fork");
	sem_close(info->sm_fork);
	sem_unlink("sm_print");
	sem_close(info->sm_print);
	sem_unlink("sm_dead");
	sem_close(info->sm_dead);
	sem_unlink("sm_done");
	sem_close(info->sm_done);
}

void	clear_simulating(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		unlink("sm_eat");
		sem_close(info->philo->sm_eat);
	}
	ft_free_info_sem(info);
	ft_free((void **) &info->philo);
}

int	error_stop(t_info *info, char *msg)
{
	print_error(msg);
	term_all_process(info);
	clear_simulating(info);
	return (1);
}

int	simulate(t_info *info)
{
	int	i;

	i = 0;
	sem_wait(info->sm_start);
	info->start_time = get_time_in_ms();
	while (i < info->num_philo)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
		{
			philo_routine(&info->philo[i]);
			return (0);
		}
		if (info->philo[i].pid < 0)
			return (error_stop(info, "fork error"));
		i++;
	}
	sem_post(info->sm_start);
	monitoring_parent(info);
	clear_simulating(info);
	return (0);
}
