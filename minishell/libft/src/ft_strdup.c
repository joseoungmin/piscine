/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:20:06 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:27:10 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	i;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (s1[++i])
		buf[i] = s1[i];
	buf[i] = '\0';
	return (buf);
}
