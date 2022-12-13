/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:55:51 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/07/06 18:22:51 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	size_t	i;

	if (!s || !f)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (s[++i])
		buf[i] = f(i, (char)s[i]);
	buf[i] = '\0';
	return (buf);
}
