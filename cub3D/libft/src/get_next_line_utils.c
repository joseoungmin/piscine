/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:17:30 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/08/21 19:52:01 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*buf;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (NULL);
	s1_len = 0;
	s2_len = ft_strlen(s2);
	if (s1)
		s1_len = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!buf)
		return (NULL);
	if (s1)
		ft_strlcpy(buf, s1, s1_len + 1);
	ft_strlcpy(buf + s1_len, s2, s2_len + 1);
	return (buf);
}

char	*ft_backup_clear(t_gnl **backup, char *data)
{
	t_gnl	*tmp;
	t_gnl	*lst;

	if (!data)
		return (NULL);
	while (*backup)
	{
		tmp = (*backup)->next;
		lst = *backup;
		if (lst->data)
		{
			free(lst->data);
			lst->data = NULL;
		}
		free(lst);
		lst = NULL;
		*backup = tmp;
	}
	return (NULL);
}

void	ft_backup_delnode(t_gnl **head, t_gnl **node)
{
	t_gnl	*front;

	if (!*head)
		return ;
	front = *head;
	if (front->fd == (*node)->fd)
	{
		*head = (*node)->next;
		free(*node);
		*node = NULL;
		return ;
	}
	while (front->next)
	{
		if (front->next->fd == (*node)->fd)
			break ;
		front = front->next;
	}
	front->next = (*node)->next;
	free(*node);
	*node = NULL;
}

t_gnl	*ft_backup_search_init(t_gnl **head, int fd)
{
	t_gnl	*node;
	t_gnl	*cur;

	cur = *head;
	if (cur && cur->fd == fd)
		return (cur);
	while (cur && cur->next)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	if (cur && cur->fd == fd)
		return (cur);
	node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!node)
		return (NULL);
	node->data = NULL;
	node->fd = fd;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
		cur->next = node;
	return (node);
}
