/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:44:44 by seojo             #+#    #+#             */
/*   Updated: 2022/07/22 19:27:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*add;

	if (!n || dest == src)
		return (dest);
	add = dest;
	while (n-- != 0)
		*(unsigned char *)add++ = *(unsigned char *)src++;
	return (dest);
}
