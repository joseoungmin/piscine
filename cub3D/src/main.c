/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:22 by seojo             #+#    #+#             */
/*   Updated: 2023/01/13 14:55:07 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef enum e_error t_err;

enum e_error
{
	EMPTY_MAP = 0,
	MANY_ARGU,
	EXTENTION,
};

void	print_argument_err(t_err err_num)
{
	const char	e_arr[3][25] = {
		"Missing map argument\n",
		"Too many argument\n",
		"Invalid map extension\n"
	};

	write(2, "Error\n", 6);
	write(2, e_arr[err_num], ft_strlen(e_arr[err_num]));
	exit(1);
}

void	check_map_extension(char *map_str)
{
	const int extension_location = ft_strlen(map_str) - 4;

	printf("check_map_extension = %s\n", map_str + extension_location);
	if (ft_strncmp(".cub", (map_str + extension_location), 4) != 0)
		print_argument_err(EXTENTION);
}

void	check_argument(int ac, char **av)
{
	if (ac == 1)
		print_argument_err(EMPTY_MAP);
	else if (ac > 2)
		print_argument_err(MANY_ARGU);
	check_map_extension(av[1]);
}

int	main(int ac, char **av)
{
	check_argument(ac, av);
	return (0);
}
