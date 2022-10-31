/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:35:44 by seojo             #+#    #+#             */
/*   Updated: 2022/10/27 17:10:17 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

# define COL_RED "\x1b[31m" 
# define COL_GREEN "\x1b[32m"
# define COL_ORIGIN "\x1b[0m"

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_philo
{
	t_info			*info;
	pthread_t		tid;
	int				id;
	long long		eat_cnt;
	long long		last_eat;
	long long		fork;
	long long		*r_fork;
	long long		*l_fork;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	*m_r_fork;
	pthread_mutex_t	*m_l_fork;
	int				tickat_num;
};

struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	long long		start_time;
	int				is_over;
	int				is_ready;
	pthread_mutex_t	m_over;
	pthread_mutex_t	m_ready;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*tickat;
	t_philo			*philo;
};

enum
{
	ERROR = -1,
	ON = 1,
	OFF = 0,
	TRUE = 1,
	FALSE = 0,
	FORK,
	EAT,
	SLEEP,
	THINK
};

int			init_info(t_info *info, char **av);
int			simulate(t_info *info);
int			print_error(char *msg);
int			print_usage(int exit_code);
long long	ft_atolld(const char *str);
void		*ft_calloc(size_t cnt, size_t size);
void		ft_free(void **ptr);
void		*philo_routine(void *arg);
long long	get_time_in_ms(void);
long long	get_time_stamp(long long start_time);
void		ft_usleep(long long time);
void		print_done(t_philo *philo);
void		print_die(t_philo *philo);
void		print_state(t_philo *philo, int state);
void		monitoring(t_info *info);

#endif
