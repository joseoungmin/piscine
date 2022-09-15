/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:09:34 by seojo             #+#    #+#             */
/*   Updated: 2022/09/15 09:08:31 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	char	**av;
	char	**envp;
	int		fd[2];
	int		in_fd;
	int		out_fd;
}	t_node;

void	ft_perror(char *str);
void	ft_msg_error(char *str, char *msg, int exit_code);
char	**msplit(char const *s, char c);
void	ft_close(int fd);
void	ft_pipe(int *fd);
void	ft_dup2(int fd1, int fd2);
char	*find_path(char **envp, char *cmd, int i);
void	init_and_open(char **av, char **envp, t_node *node);

#endif
