/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:16:44 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/08/21 19:51:50 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_and_backup(char **ones_line)
{
	int		i;
	char	*backup;
	char	*tmp;

	i = 0;
	while ((*ones_line)[i] != '\n' && (*ones_line)[i] != '\0')
		i++;
	if ((*ones_line)[i] == '\0')
		return (NULL);
	tmp = ft_substr(*ones_line, 0, i + 1);
	if (!tmp)
		return (NULL);
	backup = ft_substr(*ones_line, i + 1, ft_strlen(*ones_line) - i - 1);
	free(*ones_line);
	*ones_line = tmp;
	if (!backup)
		return (NULL);
	if (backup[0] == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	return (backup);
}

static char	*get_ones_line(t_gnl **head, char *buf, char *backup, int fd)
{
	int		read_cnt;
	int		pos;
	char	*tmp;

	pos = 0;
	read_cnt = 1;
	while (read_cnt)
	{
		if (backup && ft_strchr(backup + pos, '\n'))
			break ;
		else if (backup)
			pos += ft_strlen(backup + pos);
		read_cnt = read(fd, buf, BUFFER_SIZE);
		if (read_cnt == -1)
			return (ft_backup_clear(head, backup));
		else if (!read_cnt)
			break ;
		buf[read_cnt] = '\0';
		tmp = backup;
		backup = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		if (!backup)
			return (NULL);
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	char			*ones_line;
	static t_gnl	*backup;
	t_gnl			*node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = ft_backup_search_init(&backup, fd);
	if (!node)
		return (NULL);
	ones_line = get_ones_line(&backup, buf, node->data, fd);
	if (!ones_line)
	{
		ft_backup_delnode(&backup, &node);
		return (NULL);
	}
	node->data = split_and_backup(&ones_line);
	if (!node->data)
		ft_backup_delnode(&backup, &node);
	return (ones_line);
}
