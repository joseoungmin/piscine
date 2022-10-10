/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:24:13 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 23:39:09 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_usage(int exit_code)
{
	printf("Wrong argument! Please check usage.\n"\
			"Usage: ./philo [num_philos] [time_die] [time_eat]"\
		" [time_sleep] [num_each_philos_eat(optional)]\n");
	return (exit_code);
}

int main(int ac, char **av)
{
	if (ac != 5 || ac != 6)
		print_usage(1);


	return (0);
}
