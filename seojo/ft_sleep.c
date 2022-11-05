/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:05:45 by seojo             #+#    #+#             */
/*   Updated: 2022/11/05 12:12:12 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	m_sleep(void)
{
	long long	i;
	long long	cnt;
	long long	j;
	long long	j_cnt;

	i = 0;
	cnt = 0;
	while (i++ && cnt < LLONG_MAX)
	{
		j = 0;
		j_cnt = 0;
		while (j++ && j_cnt < LLONG_MAX)
		{
			if (j == LLONG_MAX)
			{
				j_cnt++;
				j = 0;
			}
		}
		if (i == LLONG_MAX)
		{
			cnt++;
			i = 0;
		}
	}
}

void	ms_sleep(long long time)
{
	time *= 519000;
	while (time--)
		m_sleep();
}
