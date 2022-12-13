/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:26:38 by seojo             #+#    #+#             */
/*   Updated: 2022/12/09 20:30:02 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	mpass_quotes(const char **s)
{
	const char	c = **s;

	(*s)++;
	while (**s != c)
		(*s)++;
	if (*((*s) + 1) == '\0')
		return (1);
	return (0);
}

static size_t	cnt_word(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			cnt++;
		if ((*s == '\'' || *s == '\"') && *(s + 1) != '\0')
			cnt += mpass_quotes(&s);
		s++;
	}
	return (cnt);
}

static char	*findline(char const **s, char c)
{
	char	*word_tmp;

	word_tmp = (char *)*s;
	while (**s && **s != c)
	{
		if (**s == '\'')
		{
			(*s)++;
			while (**s != '\'' && *(*s + 1) != 0)
				(*s)++;
			(*s)++;
		}
		else if (*(*s)++ == '\"')
		{
			while (**s != '\"' && *(*s + 1) != 0)
				(*s)++;
			(*s)++;
		}
	}
	return (word_tmp);
}

char	**msplit(char const *s, char c)
{
	int		words_idx;
	char	*word_tmp;
	char	**buf;

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
			word_tmp = findline(&s, c);
			buf[words_idx] = ft_substr(word_tmp, 0, s - word_tmp);
			if (*s == '\'' || *s == '\"')
				s++;
			if (buf[words_idx] == NULL)
				return (ft_free_dptr(buf, words_idx));
			words_idx++;
		}
	}
	buf[words_idx] = NULL;
	return (buf);
}
