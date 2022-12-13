/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:52:08 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/12/07 21:56:37 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*write_buffer(t_env_lst *lst, char *str, char *buf, int len_stat[2])
{
	char	*tmp;
	char	*new;
	char	*replace;

	new = ft_substr(str, 0, len_stat[0]);
	if (*new == '\'')
		replace = ft_substr(new, 1, ft_strlen(new) - 2);
	else
		replace = replace_dollar(lst, new, len_stat[1]);
	if (replace == NULL)
		error_cmd("malloc", strerror(12), 1);
	free(new);
	if (buf)
	{
		tmp = ft_strdup(buf);
		free(buf);
		buf = ft_strjoin(tmp, replace);
		free(tmp);
	}
	else
		buf = ft_substr(replace, 0, ft_strlen(replace));
	free(replace);
	return (buf);
}

static size_t	found_quotes(t_env_lst *lst, char *str, char **buf, \
		int exit_stat)
{
	char	*ptr;
	char	*tmp;
	int		len_stat[2];

	len_stat[1] = exit_stat;
	tmp = ft_substr(str, 0, 1);
	ptr = ft_strnstr(str + 1, tmp, ft_strlen(str + 1));
	len_stat[0] = (ptr - (str + 1)) + 2;
	ft_free(tmp);
	if (buf != NULL)
		*buf = write_buffer(lst, str, *buf, len_stat);
	return (len_stat[0]);
}

size_t	count_words(t_env_lst *lst, char *str, char c, int exit_stat)
{
	size_t	cnt;

	cnt = 0;
	while (str && *str)
	{
		if (*str != c && (*(str + 1) == '\0' || *(str + 1) == c))
			cnt++;
		if (str == ft_strnstr(str, "\'", 1) || str == ft_strnstr(str, "\"", 1))
		{
			str += found_quotes(lst, str, NULL, exit_stat) - 1;
			if (*str != c && (*(str + 1) == '\0' || *(str + 1) == c))
				cnt++;
		}
		str++;
	}
	return (cnt);
}

char	**split_quotes(t_env_lst *lst, char *s, char c, int exit_stat)
{
	int		words_idx;
	char	**buf;
	char	*tmp;
	int		len_stat[2];

	words_idx = 0;
	buf = buf_alloc(lst, s, c, exit_stat);
	while (*s)
	{
		if (*s == c && s++)
			continue ;
		else if (s == ft_strnstr(s, "\'", 1) || s == ft_strnstr(s, "\"", 1))
			s += found_quotes(lst, s, &buf[words_idx], exit_stat);
		else
		{
			tmp = s;
			while (*s && *s != c && *s != '\'' && *s != '\"')
				s++;
			len_and_exit_stat(&len_stat, s, tmp, exit_stat);
			buf[words_idx] = write_buffer(lst, tmp, buf[words_idx], len_stat);
		}
		if (spt_split_quotes(buf, s, c, &words_idx))
			return (NULL);
	}
	return (buf);
}
