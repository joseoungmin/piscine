/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:43:37 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:54 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	size;

	size = ft_strlen(s);
	if (size <= (size_t)start)
	{
		buf = (char *)malloc(sizeof(char));
		if (!buf)
			return (NULL);
		buf[0] = '\0';
		return (buf);
	}
	size -= start;
	if (size > len)
		size = len;
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s + start, size + 1);
	return (buf);
}
