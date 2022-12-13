/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:22:28 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/07/04 18:43:30 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, s1_len + 1);
	ft_strlcpy(buf + s1_len, s2, s2_len + 1);
	return (buf);
}
