/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:11:56 by seojo             #+#    #+#             */
/*   Updated: 2022/12/09 00:13:13 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*find_env(t_env_lst *lst, char *dollar, int exit_stat)
{
	t_env_node	*node;
	char		*find_env;
	int			i;

	if (ft_strncmp(dollar, "$ ", 2) == 0 || ft_strncmp(dollar, "$", 2) == 0 \
			|| ft_strncmp(dollar, "$\"", 2) == 0)
		return (ft_strdup("$"));
	else if (ft_strncmp(dollar, "$?", 2) == 0)
		return (ft_itoa(exit_stat));
	i = 1;
	while (dollar[i] != ' ' && dollar[i] != '\0' && dollar[i] != '$' \
			&& dollar[i] != '\"')
		i++;
	find_env = ft_substr(dollar, 1, i - 1);
	node = find_node(lst, find_env);
	ft_free(find_env);
	if (node == NULL)
		return (ft_strdup(""));
	find_env = ft_strdup(node->value);
	if (find_env == NULL)
		error_cmd("malloc", strerror(12), 1);
	return (find_env);
}

void	is_dollar(t_env_lst *lst, char **dollar, char **rt_line, \
		int exit_stat)
{
	char	*cp_rt;
	char	*find_value;
	char	*str;

	cp_rt = *rt_line;
	str = *dollar;
	if (ft_strncmp(str, "$", 1) == 0)
	{
		if (ft_strncmp(str, "$$", 2) == 0 && (*dollar)++)
			find_value = ft_strdup("");
		else if (ft_strncmp(str, "$?", 2) == 0 && (*dollar)++)
			find_value = ft_itoa(exit_stat);
		else
			find_value = find_env(lst, *dollar, exit_stat);
		if ((*dollar)++ && find_value == NULL)
			error_cmd("malloc", strerror(12), 1);
		*rt_line = ft_strjoin(cp_rt, find_value);
		ft_free(cp_rt);
		ft_free(find_value);
		if ((ft_strncmp(str, "$$", 2) == 0 || ft_strncmp(str, "$?", 2) == 0))
			return ;
		while (**dollar != '$' && **dollar != ' ' && **dollar != '\0' \
				&& **dollar != '\"')
			(*dollar)++;
	}
}

void	is_not_dollar(char **dollar, char **rt_line)
{
	char	*cp_rt;
	char	*save_line;
	char	*str;

	cp_rt = *rt_line;
	if (**dollar == '\"')
		(*dollar)++;
	str = *dollar;
	while (**dollar != '$' && **dollar != '\0' && **dollar != '\"')
		(*dollar)++;
	save_line = ft_substr(str, 0, (*dollar) - str);
	if (save_line == NULL)
		error_cmd("malloc", strerror(12), 1);
	*rt_line = ft_strjoin(cp_rt, save_line);
	ft_free(save_line);
	ft_free(cp_rt);
}

char	*replace_dollar(t_env_lst *lst, char *str, int exit_stat)
{
	char	*dollar;
	char	*rt_line;

	dollar = ft_strchr(str, '$');
	if (dollar == NULL)
	{
		if (*str == '\"')
			return (ft_substr(str, 1, ft_strlen(str) - 2));
		return (add_home_path(ft_substr(str, 0, ft_strlen(str))));
	}
	rt_line = ft_strdup("");
	if (rt_line == NULL)
		error_cmd("malloc", strerror(12), 1);
	dollar = str;
	while (*dollar != '\0')
	{
		if (ft_strncmp(dollar, "$", 1) == 0)
			is_dollar(lst, &dollar, &rt_line, exit_stat);
		else
			is_not_dollar(&dollar, &rt_line);
	}
	return (rt_line);
}
