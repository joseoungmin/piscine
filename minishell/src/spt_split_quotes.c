/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_split_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:08:03 by seojo             #+#    #+#             */
/*   Updated: 2022/12/06 16:28:54 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	spt_split_quotes(char **buf, char *s, char c, int *words_idx)
{
	if (buf[*words_idx] == NULL)
	{
		ft_free_dptr(buf, *words_idx);
		return (1);
	}
	if (*s == c)
		(*words_idx)++;
	return (0);
}

char	**buf_alloc(t_env_lst *lst, char *s, char c, int exit_stat)
{
	char	**buf;

	buf = ft_calloc(sizeof(char *), (count_words(lst, s, c, exit_stat) + 1));
	if (!s || !buf)
		return (NULL);
	return (buf);
}

void	len_and_exit_stat(int (*len_stat)[2], char *s, char *tmp, int exit_stat)
{
	(*len_stat)[0] = s - tmp;
	(*len_stat)[1] = exit_stat;
}

int	return_env_len(char *dollar)
{
	int	env_len;

	env_len = 0;
	while (*++dollar)
	{
		if (!(ft_isalnum(*dollar) || *dollar == '_'))
			break ;
		env_len++;
	}
	return (env_len);
}
