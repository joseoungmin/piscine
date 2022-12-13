/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:52:09 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/07/06 19:59:32 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	if (!dst && !src)
		return (NULL);
	str = (unsigned char *)dst;
	if (dst > src)
		while (len--)
			*(str + len) = *((unsigned char *)src + len);
	else
		while (len--)
			*str++ = *((unsigned char *)src++);
	return (dst);
}
