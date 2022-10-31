/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/29 22:51:48 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
