/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/25 18:43:11 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_usage(int exit_code)
{
	printf("Wrong argument!\nusage: ./philo number_of_philos time_to_die" 
			" time_to_eat time_to_sleep [philo_must_eat]\n");
	return (exit_code);
}

int	print_error(char *msg)
{
	while (msg && *msg)
		write(1, msg++, 1);
	write(1, "\n", 1);
	return (1);
}

/*
void	bye(void)
{
	system("leaks a.out");
}
*/

int main(int ac, char **av)
{
//	atexit(bye);
	t_info	info;

	if (ac < 5 || 6 < ac)
		return (print_usage(1));
	if (init_info(&info, av))
		return (1);
	if (simulate(&info))
		return (1);
	return (0);
}
