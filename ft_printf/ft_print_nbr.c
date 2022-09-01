/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:54:47 by seojo             #+#    #+#             */
/*   Updated: 2022/08/16 18:12:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = write(1, num, ft_strlen(num));
	free(num);
	return (len);
}

int	ft_print_text(va_list ap, char type)
{
	char	c;
	char	*s;

	if (type == 'c')
	{
		c = va_arg(ap, int);
		return (write(1, &c, 1));
	}
	if (type == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
			return (write(1, "(null)", 6));
		return (write(1, s, ft_strlen(s)));
	}
	return (-1);
}
