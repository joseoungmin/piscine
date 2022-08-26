/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:30:34 by seojo             #+#    #+#             */
/*   Updated: 2022/08/26 23:09:17 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	s = ft_strlen(src);

	if (size)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == 0)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s) - start > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char			*buf;
	size_t			s1_size;
	const size_t	s2_size = ft_strlen(s2);

	if (!s2)
		return (NULL);
	s1_size = 0;
	if (s1 != NULL)
		s1_size = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!buf)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(buf, s1, s1_size + 1);
	ft_strlcpy(buf + s1_size, s2, s2_size + 1);
	return (buf);
}
