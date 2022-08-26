/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:30:10 by seojo             #+#    #+#             */
/*   Updated: 2022/08/26 23:30:21 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_lst	*check_fd(t_lst **back, int fd)
{
	t_lst	*tmp;
	t_lst	*cur;

	cur = *back;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		if (cur->next == NULL)
			break ;
		cur = cur->next;
	}
	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = NULL;
	if (!*back)
		*back = tmp;
	else
		cur->next = tmp;
	return (tmp);
}

static char	*read_line(char *buf, char *back, int fd)
{
	char	*tmp;
	int		size;

	size = 1;
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		else if (!size)
			break ;
		tmp = back;
		buf[size] = '\0';
		back = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (!back)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (back);
}

static void	dellst(t_lst **back, t_lst **lst_buf)
{
	t_lst	*point;

	if (!*back)
		return ;
	point = *back;
	if (point->fd == (*lst_buf)->fd)
		*back = (*lst_buf)->next;
	else
	{
		while (point->next)
		{
			if (point->next->fd == (*lst_buf)->fd)
				break ;
			point = point->next;
		}
		point->next = (*lst_buf)->next;
	}
	free(*lst_buf);
	*lst_buf = NULL;
}

static char	*insert_newline(char **rt_line)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	while ((*rt_line)[i] != '\n' && (*rt_line)[i] != '\0')
		i++;
	if ((*rt_line)[i] == '\0')
		return (NULL);
	tmp = ft_substr(*rt_line, 0, i + 1);
	if (!tmp)
		return (NULL);
	str = ft_substr(*rt_line, i + 1, ft_strlen(*rt_line) - i - 1);
	free(*rt_line);
	*rt_line = tmp;
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	char			*rt_line;
	static t_lst	*back;
	t_lst			*lst_buf;

	if (fd < 0 | BUFFER_SIZE <= 0)
		return (NULL);
	lst_buf = check_fd(&back, fd);
	if (!lst_buf)
		return (NULL);
	rt_line = read_line(buf, lst_buf->str, fd);
	if (!rt_line)
	{
		dellst(&back, &lst_buf);
		return (NULL);
	}
	lst_buf->str = insert_newline(&rt_line);
	if (lst_buf->str == NULL)
		dellst(&back, &lst_buf);
	return (rt_line);
}
