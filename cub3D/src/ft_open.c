/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:50:50 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 16:51:01 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_open.h"

int	ft_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (errno == 2)
		err_exit("No such file or directory");
	else if (errno == 13)
		err_exit("Permission denied");
	else if (fd < 0)
		err_exit("File open error");
	return (fd);
}
