/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:40:35 by seojo             #+#    #+#             */
/*   Updated: 2022/09/21 16:11:15 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			cnt++;
		s++;
	}
	return (cnt);
}

static char	**ft_free_dptr(char	**s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words_idx;
	char	*word_tmp;
	char	**buf;

	buf = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!s || !buf)
		return (NULL);
	words_idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_tmp = (char *)s;
			while (*s && *s != c)
				s++;
			buf[words_idx] = ft_substr(word_tmp, 0, s - word_tmp);
			if (!buf[words_idx++])
				return (ft_free_dptr(buf, words_idx - 1));
		}
	}
	return (buf);
}
