/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:20:29 by seojo             #+#    #+#             */
/*   Updated: 2022/12/02 23:55:42 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	check_n_option(char *cmd)
{
	if (!(*cmd == '-'))
		return (0);
	while (*++cmd)
		if (!(*cmd == 'n'))
			return (0);
	return (1);
}

int	ft_echo(char **cmd)
{
	int	flag;
	int	i;

	flag = 0;
	if (!cmd[1])
	{
		printf("\n");
		return (0);
	}
	if (check_n_option(cmd[1]))
		flag = 1;
	i = 0;
	while (cmd[++i])
	{
		if (flag && check_n_option(cmd[i]))
			continue ;
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
