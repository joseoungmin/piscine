/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:47:57 by seojo             #+#    #+#             */
/*   Updated: 2022/08/16 18:07:06 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list ap, const char format)
{
	if (format == '\0')
		return (-2);
	else if (format == 'c' || format == 's')
		return (ft_print_text(ap, format));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	else if (format == 'p')
		return (ft_print_hex(va_arg(ap, unsigned long), format));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (write(1, "%", 1));
	return (write(1, &format, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		rtn;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			rtn = ft_formats(ap, *++format);
		else
			rtn = write(1, format, 1);
		if (rtn == -2)
			break ;
		else if (rtn < 0)
		{
			va_end(ap);
			return (-1);
		}
		len += rtn;
		format++;
	}
	va_end(ap);
	return (len);
}
