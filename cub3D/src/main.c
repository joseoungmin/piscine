/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/13 12:10:16 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef enum e_error t_err;

enum e_error
{
	ARGU,
};

void	error_exit(t_err err_no)
{
	const char	e_arr[7][8] = {
		"Error"};
	(void)e_arr;
	(void)err_no;
}

void	check_argument(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		;
	//	error_exit()
}

int	main(int ac, char **av)
{
	check_argument(ac, av);
	return (0);
}
