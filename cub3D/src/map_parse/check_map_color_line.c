/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_color_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:43:33 by seojo             #+#    #+#             */
/*   Updated: 2023/02/09 20:52:27 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_color_line.h"

char	*pass_space(char *read_line)
{
	while (ft_isspace(*read_line) == 1)
		read_line++;
	return (read_line);
}

static void	check_alpha(char *read_line)
{
	while (*read_line != '\0')
		if (ft_isalpha(*read_line++))
			err_exit("invalid color argument");
}

static void	check_blank(char *read_line)
{
	char	c;

	read_line = pass_space(read_line);
	while (*read_line != '\0')
	{
		if (*read_line == ' ')
		{
			read_line = pass_space(read_line);
			if (!(*read_line == ',') && \
					(ft_isdigit(c) && ft_isdigit(*read_line)) && \
					!(*read_line == '\0'))
				err_exit("invalid color argument");
		}
		else
		{
			c = *read_line;
			read_line++;
		}
	}
}

void	check_line(char *read_line)
{
	check_alpha(read_line);
	check_blank(read_line);
}
