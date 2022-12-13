/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:47:35 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 19:04:54 by jiyonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include "structure.h"
# include "libft.h"
# include "ft_error.h"
# include "built_in.h"
# include "ft_signal.h"
# include "open_close.h"
# include "minishell.h"
# include <string.h>
# include <sys/wait.h>
# include <dirent.h>

/*		command_executer.c		*/
void	command_executer(t_env_lst *lst, t_cmd_unit *unit, int *exit_stat);
char	*ft_path_join(char *paths, char *cmd);
char	*parse_command(char *cmd, char **paths);
int		is_direc(char *path, char *cmd, int tmp_errno);

/*		executer.c				*/
void	execute_process(t_env_lst *lst, t_cmd_unit *cmd_unit, \
		int oldfd[2], int *exit_stat);
int		ft_wait(pid_t pid);

#endif
