/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:09:34 by seojo             #+#    #+#             */
/*   Updated: 2022/09/12 13:26:46 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
	char	*path2;
}	t_node;

void	ft_perror(char *str);
void	ft_msg_error(char *str, char *msg, int exit_code);
char	**msplit(char const *s, char c);
void	node_init(int ac, char **av, char **envp, t_node *node);
void	free_single_ptr(char *str);
void	free_double_ptr(char **str);
void	free_node(t_node *node);
void	fd_close(int fd1, int fd2);

#endif
