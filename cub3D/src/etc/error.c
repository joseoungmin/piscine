/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:21 by seojo             #+#    #+#             */
/*   Updated: 2023/02/14 19:57:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	string_len(char *str)
{
	const char	*tmp = str;

	while (str && *str)
		str++;
	return (str - tmp);
}

void	err_exit(char *err_msg)
{
	write(2, "Error\n", 6);
	write(2, err_msg, string_len(err_msg));
	write(2, "\n", 1);
	exit(0);
}
