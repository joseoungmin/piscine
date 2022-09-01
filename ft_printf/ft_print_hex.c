/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:48:35 by seojo             #+#    #+#             */
/*   Updated: 2022/08/17 12:16:30 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned long n, unsigned long base_len)
{
	int	len;

	len = 1;
	while (n >= base_len)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

static char	*ft_itoa_base(unsigned long n, char *base, int base_len)
{
	char		*buf;
	int			len;

	len = ft_intlen(n, base_len);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	while (--len >= 0)
	{
		buf[len] = base[n % base_len];
		n /= base_len;
	}
	return (buf);
}

int	ft_print_hex(unsigned long num, const char format)
{
	int		len;
	int		total;
	char	*tmp;

	len = 0;
	total = 0;
	if (format == 'p')
		len = write(1, "0x", 2);
	total += len;
	if (len < 0)
		return (-1);
	if (format == 'X')
		tmp = ft_itoa_base(num, "0123456789ABCDEF", 16);
	else
		tmp = ft_itoa_base(num, "0123456789abcdef", 16);
	if (tmp == 0)
		return (-1);
	len = write(1, tmp, ft_strlen(tmp));
	if (len < 0)
		total = -1;
	else
		total += len;
	free(tmp);
	return (total);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_itoa_base(n, "0123456789", 10);
	if (num == 0)
		return (-1);
	len = write(1, num, ft_strlen(num));
	free(num);
	return (len);
}
