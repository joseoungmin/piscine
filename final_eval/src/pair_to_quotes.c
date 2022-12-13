/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_to_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:27:48 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/12/05 18:41:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static size_t	double_quote(char *str, char **buf)
{
	char	*line;
	char	*tmp;

	*buf = ft_strchr(str + 1, '\"');
	if (*buf > str)
		return (*buf - str);
	else
	{
		*buf = ft_strdup("");
		while (TRUE)
		{
			line = readline("> ");
			tmp = ft_strjoin(*buf, "\n");
			free(*buf);
			*buf = ft_strjoin(tmp, line);
			free(tmp);
			if (ft_strchr(line, '\"'))
			{
				free(line);
				break ;
			}
			free(line);
		}
	}
	return (0);
}

static size_t	single_quote(char *str, char **buf)
{
	char	*line;
	char	*tmp;

	*buf = ft_strchr(str + 1, '\'');
	if (*buf > str)
		return (*buf - str);
	else
	{
		*buf = ft_strdup("");
		while (TRUE)
		{
			line = readline("> ");
			tmp = ft_strjoin(*buf, "\n");
			free(*buf);
			*buf = ft_strjoin(tmp, line);
			free(tmp);
			if (ft_strchr(line, '\''))
			{
				free(line);
				break ;
			}
			free(line);
		}
	}
	return (0);
}

static void	not_pair(char **s, char **ptr, char **buf)
{
	char	*tmp;

	tmp = ft_strdup(*ptr);
	free(*ptr);
	*ptr = ft_strjoin(tmp, *buf);
	free(tmp);
	free(*buf);
	*s = *ptr;
}

static t_bool	is_quotes(char **s, char **ptr, char **buf)
{
	size_t	size;

	if (*s == ft_strnstr(*s, "\'", 1))
	{
		size = single_quote(*s, buf);
		if (size)
			*s += size;
		else
		{
			not_pair(s, ptr, buf);
			return (TRUE);
		}
	}
	else if (*s == ft_strnstr(*s, "\"", 1))
	{
		size = double_quote(*s, buf);
		if (size)
			*s += size;
		else
		{
			not_pair(s, ptr, buf);
			return (TRUE);
		}
	}
	return (FALSE);
}

char	*pair_to_quotes(char *s)
{
	char	*ptr;
	char	*buf;

	ptr = s;
	buf = NULL;
	while (s && *s)
	{
		if (is_quotes(&s, &ptr, &buf))
			continue ;
		s++;
	}
	return (ptr);
}
