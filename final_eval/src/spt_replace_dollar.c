/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_replace_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:21:46 by seojo             #+#    #+#             */
/*   Updated: 2022/12/06 21:28:21 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*add_home_path(char	*cmd)
{
	char	*home_path;

	if (ft_strncmp(cmd, "~", 2) == 0)
	{
		home_path = ft_strdup(getenv("HOME"));
		ft_free(cmd);
		cmd = home_path;
	}
	else if (ft_strncmp(cmd, "~/", 2) == 0)
	{
		home_path = ft_strjoin(getenv("HOME"), (cmd + 1));
		ft_free(cmd);
		cmd = home_path;
	}
	return (cmd);
}
