/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:48:46 by seojo             #+#    #+#             */
/*   Updated: 2023/02/19 12:48:47 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_file.h"

char	*split_filename(char *line)
{
	int		idx;
	char	*filename;

	idx = 0;
	while (line[idx] && line[idx] != ' ' && line[idx] != '\n')
		idx++;
	filename = ft_substr(line, 0, idx);
	if (filename == NULL)
		err_exit("split_filename : malloc failed");
	return (filename);
}

static void	check_blank(char *read_line)
{
	read_line = pass_space(read_line);
	while (*read_line != '\0')
		if (*read_line++ == ' ')
			err_exit("invalid path object : blank");
}

char	*check_path(char *read_line)
{
	int		fd;
	char	*filename;

	read_line = pass_space(read_line);
	check_blank(read_line);
	if (*read_line == '\n' || *read_line == '\0')
		err_exit("Invalid path object");
	filename = split_filename(read_line);
	fd = ft_open(filename);
	close(fd);
	return (filename);
}

char	*check_texture_file(t_world *world, char *read_line, int rot)
{
	if (world->tex_path[rot] != NULL)
		err_exit("Too many texture paths");
	return (check_path(read_line));
}
