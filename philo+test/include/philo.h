/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:35:44 by seojo             #+#    #+#             */
/*   Updated: 2022/10/18 20:26:58 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	t_info		*info;
	pthread_t	tid;
	long long	id;
	long long	eat_cnt;
	long long	last_eat;
	long long	stat_fork;
}

typedef struct s_info
{
	t_philo		*philo;
	long long	num_philo;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	long long	must_eat;
	long long	start_time;
	long long	is_over;
}

enum
{
	ERROR = -1,
	ON = 1,
	OFF = 0,
}

#endif
