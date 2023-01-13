/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/13 13:53:17 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef enum e_error t_err;

enum e_error
{
	ARGU = 0,
};

void	error_exit(t_err err_num)
{
	const char	e_arr[7][20] = {
		"Wrong arguments\n"};
	write(2, "Error\n", 6);
	write(2, e_arr[err_num], ft_strlen(e_arr[err_num]));
}

void	check_argument(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		error_exit(ARGU);
}

int	main(int ac, char **av)
{
	check_argument(ac, av);
	return (0);
}
