/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:38:44 by seojo             #+#    #+#             */
/*   Updated: 2022/12/08 15:45:41 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

long long	ft_atolld(const char *str)
{
	const long long	max = LLONG_MAX / 10;
	long long		num;
	int				sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
		if (!ft_isdigit(*str))
			return (0);
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if (num > max || (num == max && *str > '7' + (sign == -1)))
			return (0);
		num = num * 10 + *str++ - '0';
	}
	if (*str == '\0')
		return (num * sign);
	return (0);
}

static int	check_digit(char *cmd)
{
	if (*cmd == '-' || *cmd == '+')
		cmd++;
	while (cmd && *cmd)
		if (!ft_isdigit(*cmd++))
			return (1);
	return (0);
}

int	ft_exit(char **cmd)
{
	long long	exit_num;

	printf("exit\n");
	if (!cmd[1])
		exit(0);
	exit_num = ft_atolld(cmd[1]);
	if ((exit_num == 0 && ft_strncmp(cmd[1], "0", 2)) || check_digit(cmd[1]))
	{
		error_cmd_path("exit", cmd[1], "numeric argument required", 0);
		exit(255);
	}
	else if (cmd[2])
		return (error_cmd("exit", "too many arguments", 0));
	else
		exit (exit_num);
}
