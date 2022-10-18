/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:16:00 by seojo             #+#    #+#             */
/*   Updated: 2022/10/17 14:31:26 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


/*
void bye(void)
{
	system("leaks a.out");
}
*/

int main(int ac, char **av)
{
	//atexit(bye);
	t_info	info;

	if (ac < 5 || ac > 6)
		return (print_usage(ERROR));
	if (init_info(&info, av) == ERROR)
		return (ERROR);
	if (ft_simulate(&info) == ERROR)
		return (ERROR);
	return (0);
}
