/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:35:44 by seojo             #+#    #+#             */
/*   Updated: 2022/11/04 15:29:33 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define COL_RED "\x1b[31m" 
# define COL_GREEN "\x1b[32m"
# define COL_ORIGIN "\x1b[0m"

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_philo
{
	t_info		*info;
	int			id;
	sem_t		*sm_eat;
	pid_t		pid;
	pthread_t	tid;
	long long	eat_cnt;
	long long	last_eat;
};

struct s_info
{
	int			num_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			must_eat;
	int			is_dead;
	long long	start_time;
	sem_t		*sm_done;
	sem_t		*sm_fork;
	sem_t		*sm_start;
	sem_t		*sm_dead;
	sem_t		*sm_print;
	t_philo		*philo;
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

long long	ft_atolld(const char *str);
void		*ft_calloc(size_t cnt, size_t size);
void		ft_free(void **ptr);
void		philo_routine(t_philo *philo);
long long	get_time_in_ms(void);
long long	get_time_stamp(long long start_time);
void		ft_usleep(long long time);
int			print_error(char *msg);
int			print_usage(int exit_code);
void		print_done(t_philo *philo);
void		print_die(t_philo *philo);
void		print_state(t_philo *philo, int state);
void		monitoring(t_info *info);
void		monitoring_parent(t_info *info);
void		monitoring_philo(t_philo *philo);
void		term_all_process(t_info *info);
int			error_stop(t_info *info, char *msg);
int			init_info(t_info *info, char **av);
int			simulate(t_info *info);

#endif
