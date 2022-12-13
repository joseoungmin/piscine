/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:53:49 by jiyonpar          #+#    #+#             */
/*   Updated: 2022/12/10 19:36:40 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "print_gd.h"
# include "parse.h"
# include "ft_signal.h"
# include "open_close.h"
# include "executer.h"
# include "built_in.h"
# include "shell_lv_up.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/*			main.c				*/
void		gd_shell(t_env_lst *lst, int exit_stat);
#endif
