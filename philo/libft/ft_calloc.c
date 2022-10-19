/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:33:29 by seojo             #+#    #+#             */
/*   Updated: 2022/10/19 13:07:07 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*buf;
	void	*ptr;
	int		i;

	i = cnt * size;
	buf = (void *)malloc(cnt * size);
	if (!buf)
		return (NULL);
	ptr = buf;
	while (i-- != 0)
		*(char *)buf++ = 0;
	return (ptr);
}
