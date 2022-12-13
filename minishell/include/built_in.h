/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:46:52 by seojo             #+#    #+#             */
/*   Updated: 2022/12/08 15:44:55 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "structure.h"
# include "libft.h"
# include "ft_free.h"
# include "ft_error.h"
# include "crud.h"
# include <stdio.h>
# include <limits.h>

/*		ft_env.c		*/
int			ft_env(t_env_lst *lst);
t_env_lst	*envp_cpy(char **envp);

/*		ft_pwd.c		*/
int			ft_pwd(void);

/*		ft_echo.c 		*/
int			ft_echo(char **cmd);

/*		ft_unset.c		*/
int			ft_unset(t_env_lst *lst, char **cmd);
int			check_envp_cmd(char *cmd);

/*		ft_cd.c			*/
int			ft_cd(t_env_lst *lst, char **cmd);

/*		ft_export.c		*/
int			ft_export(t_env_lst *lst, char **cmd);

/*		ft_exit.c		*/
int			ft_exit(char **cmd);
long long	ft_atolld(const char *str);

/*		check_built_in.c	*/
int			check_built_in(char *cmd);
void		play_built_in(t_env_lst *lst, char **cmd, int type, int *exit_stat);

#endif
