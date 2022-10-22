/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:35:44 by seojo             #+#    #+#             */
/*   Updated: 2022/10/22 12:02:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_philo
{
	t_info			*info;
	pthread_t		tid;
	long long		id;
	long long		eat_cnt;
	long long		last_eat;
	long long		stat_fork;
	long long		*stat_r_fork;
	long long		*stat_l_fork;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
};

struct s_info
{
	t_philo			*philo;
	long long		num_philo;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		must_eat;
	long long		start_time;
	long long		is_over;
	long long		is_ready;
	pthread_mutex_t	m_over;
	pthread_mutex_t	m_ready;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_main_mutex;
	pthread_mutex_t	*fors_mutex;
};

enum
{
	ERROR = -1,
	ON = 1,
	OFF = 0,
};


int			init_info(t_info *info, char **av);
int			simulate(t_info *info);
int			print_error(char *msg);
int			print_usage(int exit_code);
//utils
long long	ft_atolld(const char *str);
void		*ft_calloc(size_t cnt, size_t size);
void		ft_free(void **ptr);

#endif
