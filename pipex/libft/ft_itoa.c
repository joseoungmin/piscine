/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:42:12 by seojo             #+#    #+#             */
/*   Updated: 2022/07/19 09:12:45 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*buf;
	long long	num;
	int			len;
	int			negative;

	num = (long long)n;
	len = ft_intlen(num);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	negative = 0;
	if (num < 0)
	{
		negative = 1;
		buf[0] = '-';
		num *= -1;
	}
	while (--len >= negative)
	{
		buf[len] = num % 10 + '0';
		num /= 10;
	}
	return (buf);
}
