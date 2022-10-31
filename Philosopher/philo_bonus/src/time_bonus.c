/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:50:06 by seojo             #+#    #+#             */
/*   Updated: 2022/10/30 02:36:30 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)(time.tv_sec * 1e3) \
			+ (long long)(time.tv_usec / 1e3));
}

long long	get_time_stamp(long long start_time)
{
	long long	end_time;

	end_time = get_time_in_ms();
	return (end_time - start_time);
}

void	ft_usleep(long long time)
{
	long long	start_time;

	start_time = get_time_in_ms();
	while (time >= get_time_in_ms() - start_time)
		usleep(500);
}
