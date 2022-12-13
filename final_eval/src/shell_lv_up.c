/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lv_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:36:34 by seojo             #+#    #+#             */
/*   Updated: 2022/12/06 19:01:33 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_lv_up.h"

static int	ft_lldlen(long long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*lldtoa(long long num)
{
	char	*buf;
	int		len;

	len = ft_lldlen(num);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	while (--len >= 0)
	{
		buf[len] = num % 10 + '0';
		num /= 10;
	}
	return (buf);
}

static void	shell_name_change(t_env_lst *lst)
{
	t_env_node	*node;
	char		*gdshell;

	gdshell = malloc(8);
	gdshell[0] = 'G';
	gdshell[1] = 'D';
	gdshell[2] = 's';
	gdshell[3] = 'h';
	gdshell[4] = 'e';
	gdshell[5] = 'l';
	gdshell[6] = 'l';
	gdshell[7] = '\0';
	node = find_node(lst, "SHELL");
	if (gdshell == NULL || node == NULL)
		return ;
	free(node->value);
	node->value = gdshell;
}

void	shell_lv_up(t_env_lst *lst)
{
	long long	shell_lv;
	t_env_node	*node;

	shell_name_change(lst);
	node = find_node(lst, "SHLVL");
	if (!node)
		return ;
	shell_lv = ft_atolld(node->value);
	if (shell_lv <= 0)
		return ;
	free(node->value);
	node->value = lldtoa(shell_lv + 1);
}
