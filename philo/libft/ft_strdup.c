/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:34:27 by seojo             #+#    #+#             */
/*   Updated: 2022/07/19 08:35:06 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	i;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (s[++i])
		buf[i] = s[i];
	buf[i] = '\0';
	return (buf);
}
