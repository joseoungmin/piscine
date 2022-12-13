/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:46:12 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 18:30:23 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void	ft_free(char *ptr)
{
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
}

char	**ft_free_dptr(char **s, int i)
{
	while (--i >= 0)
		ft_free(s[i]);
	free(s);
	s = NULL;
	return (NULL);
}
