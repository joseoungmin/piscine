/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:34:25 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/07/06 19:59:03 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;

	if (!dst && !src)
		return (NULL);
	str = (unsigned char *)dst;
	while (n--)
		*str++ = *((unsigned char *)src++);
	return (dst);
}
