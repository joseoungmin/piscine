/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:09:34 by seojo             #+#    #+#             */
/*   Updated: 2022/09/13 18:00:58 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int		ac;
	char	**av;
	char	**envp;
	char	*path;
}	t_node;

typedef struct s_fd
{
	int	fd[2];
}	t_fd;

void	ft_perror(char *str);
void	ft_msg_error(char *str, char *msg, int exit_code);
char	**msplit(char const *s, char c);
void	node_init(int ac, char **av, char **envp, t_node *node);
void	free_single_ptr(char *str);
void	free_double_ptr(char **str);
void	free_node(t_node *node);
void	fd_close(int fd1, int fd2);
void	fd_close_all(t_fd **fd_set, int last);
char	*find_path(char **envp, char *cmd, int i);

#endif
