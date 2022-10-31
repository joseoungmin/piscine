/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/29 22:38:54 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || 6 < ac)
		return (print_usage(1));
	if (init_info(&info, av))
		return (1);
	if (simulate(&info))
		return (1);
	return (0);
}
