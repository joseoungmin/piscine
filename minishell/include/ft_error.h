/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:27:07 by seojo             #+#    #+#             */
/*   Updated: 2022/12/04 13:02:14 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include "libft.h"
# include <sys/errno.h>
# include <string.h>

/*		ft_error.c			*/
int		error_cmd_path(char *cmd, char *path, char *err, int check);
int		error_cmd(char *cmd, char *err, int flag);
int		error_syntax(char *c);

/*		ft_error_exit.c		*/
void	ft_close(int fd);
void	ft_pipe(int pipe_fd[2]);
pid_t	ft_fork(void);
void	ft_dup2(int fd1, int fd2);

#endif
