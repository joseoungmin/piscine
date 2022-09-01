/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:48:36 by seojo             #+#    #+#             */
/*   Updated: 2022/08/16 19:41:09 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_formats(va_list ap, const char format);
int		ft_print_text(va_list ap, char type);
int		ft_print_nbr(int n);
int		ft_print_hex(unsigned long num, const char format);
int		ft_print_unsigned(unsigned int n);

#endif
