/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:33:29 by seojo             #+#    #+#             */
/*   Updated: 2022/10/18 20:23:53 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*buf;

	buf = (void *)malloc(cnt * size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, cnt * size);
	return (buf);
}
