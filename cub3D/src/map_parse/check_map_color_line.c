/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_color_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:43:33 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 19:41:36 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_color_line.h"

char	*pass_space(char *read_line)
{
	while (ft_isspace(*read_line) == 1)
		read_line++;
	return (read_line);
}

static void	check_invalid(char *read_line)
{
	int	comma_cnt;

	comma_cnt = 0;
	while (*read_line != '\0')
	{
		if (*read_line == ',')
			comma_cnt++;
		if (!ft_isdigit(*read_line) && *read_line != ',' && *read_line != '\n')
			err_exit("invalid color object");
		read_line++;
	}
	if (comma_cnt != 2)
		err_exit("invalid color object");
}

static void	check_blank(char *read_line)
{
	read_line = pass_space(read_line);
	while (*read_line != '\0')
		if (*read_line++ == ' ')
			err_exit("invalid color object : blank");
}

void	check_line(char *read_line)
{
	check_invalid(read_line);
	check_blank(read_line);
}
