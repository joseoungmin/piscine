/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:59:51 by seojo             #+#    #+#             */
/*   Updated: 2022/06/30 19:59:58 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n-- != 0)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		if (*(unsigned char *)src - 1 == (unsigned char)c)
			return (dest);
	}
	return (NULL);
}
