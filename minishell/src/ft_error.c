/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:11:38 by seojo             #+#    #+#             */
/*   Updated: 2022/12/09 16:00:04 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	error_cmd_path(char *cmd, char *path, char *err, int check)
{
	ft_putstr_fd("GDshell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (check)
	{
		ft_putstr_fd(": `", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("': ", 2);
	}
	else
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	error_cmd(char *cmd, char *err, int flag)
{
	ft_putstr_fd("GDshell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	if (flag == 0)
		return (1);
	exit(flag);
}

int	error_syntax(char *c)
{
	ft_putstr_fd("GDshell: ", 2);
	ft_putstr_fd("syntax error near unexpected token `", 2);
	if (ft_strncmp(c, ">>", 2) == 0 || ft_strncmp(c, "<<", 2) == 0)
		write(2, c, 2);
	else if (*c == '<' || *c == '>')
		write(2, c, 1);
	else
		write(2, c, ft_strlen(c));
	ft_putstr_fd("'\n", 2);
	return (1);
}
