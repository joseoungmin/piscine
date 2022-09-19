/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:30:34 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 22:58:21 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char			*buf;
	size_t			s1_size;
	const size_t	s2_size = ft_strlen(s2);

	if (!s2)
		return (NULL);
	s1_size = 0;
	if (s1 != NULL)
		s1_size = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!buf)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(buf, s1, s1_size + 1);
	ft_strlcpy(buf + s1_size, s2, s2_size + 1);
	return (buf);
}

char	*allclear(t_lst **head, char *str)
{
	t_lst	*tmp;

	if (!str)
		return (NULL);
	while (*head)
	{
		tmp = (*head)->next;
		if ((*head)->str)
		{
			free((*head)->str);
			(*head)->str = NULL;
		}
		free(*head);
		*head = tmp;
	}
	return (NULL);
}
