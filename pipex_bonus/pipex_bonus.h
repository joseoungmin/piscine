/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:09:34 by seojo             #+#    #+#             */
/*   Updated: 2022/09/14 00:22:18 by seojo            ###   ########.fr       */
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
	int		fd[2];
	int		in_fd;
	int		out_fd;
	int		heredoc;
}	t_node;

typedef struct s_fd
{
	int	fd[2];
}	t_fd;

void	ft_perror(char *str);
void	ft_msg_error(char *str, char *msg, int exit_code);
char	**msplit(char const *s, char c);
void	node_init(int ac, char **av, char **envp, t_node *node);
void	free_sptr(char *str);
void	free_dptr(char **str);
void	ft_close(int fd);
void	ft_dup2(int fd1, int fd2);
char	*find_path(char **envp, char *cmd, int i);

#endif
