/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:24:53 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 20:38:49 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_argument.h"

void	check_map_extension(char *map_str)
{
	const int	extension_location = ft_strlen(map_str) - 4;

	if (ft_strncmp(".cub", (map_str + extension_location), 5) != 0)
		err_exit("Invalid map extension");
}

void	check_argument(int ac, char **av)
{
	if (ac == 1)
		err_exit("Missing map argument");
	else if (ac > 2)
		err_exit("Too many argument");
	check_map_extension(av[1]);
}
