/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:37:11 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 03:20:28 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_CLOSE_H
# define OPEN_CLOSE_H
# include "ft_error.h"
# include "structure.h"
# include "executer.h"
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>

/*		open_close.c		*/
int		ft_access(char *cmd_path, int num);
int		ft_open(char *file, int type);
int		dup_redirection(t_cmd_unit *unit, int stdoutfd, int *exit_stat);

/*		heredoc.c			*/
void	unlink_docfile(void);
int		check_heredoc(t_cmd_unit *unit);

#endif
