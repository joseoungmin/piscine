/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:08:58 by seojo             #+#    #+#             */
/*   Updated: 2022/10/17 15:13:11 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define COL_RED "\x1b[31m" 
# define COL_GREEN "\x1b[32m"
# define COL_ORIGIN "\x1b[0m"

struct	s_info;

typedef struct s_philo
{
	struct s_info	*info;
	pthread_t		tid;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				has_r_fork;
	int				has_l_fork;
	int				stat_fork;
	int				*stat_r_fork;
	int				*stat_l_fork;
	uint64_t		id;
	uint64_t		meal_cnt;
	uint64_t		last_meal;
}					t_philo;

typedef struct s_info
{
	int				num_philo;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	uint64_t		must_eat;
	uint64_t		start_time;
	int				is_over;
	int				is_ready;
	pthread_mutex_t	m_over;
	pthread_mutex_t	m_ready;
	pthread_mutex_t	m_print;
	pthread_mutex_t	main_mutex;
	pthread_mutex_t	*forks_mutex;
	t_philo			*philo;
}					t_info;

enum
{
	OFF = 0,
	ON = 1,
	FALSE = 0,
	TRUE = 1,
	ERROR = -1,
	FORK,
	EAT,
	SLEEP,
	THINK,
};

int		philo_atoi(const char *str);
int		print_usage(int exit_code);
int		init_info(t_info *info, char **av);
int		print_error(char *msg);
void	ft_free(void **ptr);
int		ft_simulate(t_info *info);
void	*ft_philo_routine(void *arg);
void	ft_take_forks(t_philo *a_philo);
void	ft_monitoring(t_info *info);
void	ft_print_done(t_philo *philo);
void	ft_print_die(t_philo *philo);
void	ft_print_state(t_philo *philo, int state);
long long	ft_get_time_in_ms(void);
long long	ft_get_time_stamp(long long start_time);
void	ft_usleep(long long time);

#endif
