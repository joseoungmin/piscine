/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:26:38 by seojo             #+#    #+#             */
/*   Updated: 2022/09/12 23:36:47 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	cnt_word(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == '\'')
		{
			while (*(++s) != '\'' && *(s + 1) != 0)
				;
			cnt++;
		}
		if (*s == '\"')
		{
			while (*(++s) != '\"' && *(s + 1) != 0)
				;
			cnt++;
		}
		else if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
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

static char	*findline(char const **s, char c, int *flag)
{
	char	*word_tmp;

	word_tmp = (char *)*s;
	while (**s && **s != c)
	{
		if (**s == '\'')
		{
			(*s)++;
			*flag = 1;
			word_tmp++;
			while (**s != '\'' && *(*s + 1) != 0)
				(*s)++;
			break ;
		}
		else if (*(*s)++ == '\"')
		{
			*flag = 1;
			word_tmp++;
			while (**s != '\"' && *(*s + 1) != 0)
				(*s)++;
			break ;
		}
	}
	return (word_tmp);
}

char	**msplit(char const *s, char c)
{
	int		words_idx;
	char	*word_tmp;
	char	**buf;
	int		sflag;

	buf = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!s || !buf)
		return (NULL);
	words_idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_tmp = findline(&s, c, &sflag);
			buf[words_idx] = ft_substr(word_tmp, 0, s - word_tmp);
			if (sflag == 1)
				s++;
			if (!buf[words_idx++])
				return (ft_free_dptr(buf, words_idx - 1));
		}
	}
	buf[words_idx] = NULL;
	return (buf);
}
