/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:11:48 by seojo             #+#    #+#             */
/*   Updated: 2022/07/19 08:14:56 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dest > src)
		while ((int)--n >= 0)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	else
		while (++i < n)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	return (dest);
}
