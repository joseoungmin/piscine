/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crud.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:56:27 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 18:27:36 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRUD_H
# define CRUD_H
# include "structure.h"
# include "libft.h"
# include "parse.h"
# include "ft_free.h"
# include "ft_error.h"
# include "open_close.h"

/*		unit_crud.c		*/
t_cmd_unit	*split_pipe_cmd(t_env_lst *lst, char *cmd, int *exit_stat);
void		del_one_unit(t_cmd_unit *unit);
t_env_node	*add_new_node(t_env_lst *lst, char *key);

/*		redir_crud.c	*/
int			del_redir_in_cmd(t_cmd_unit *unit, char *cmd, int *exit_stat);

/*		spt_redir_crud.c	*/
void		del_all_redir(t_redir *redir);
void		idx_plus(char *cmd, int *i);
int			type_error(char *cmd, int type, int *i);
int			rt_idx(char *cmd, char c, int *i);
int			rt_copy(char *cmd, int *i);

/*		envp_crud.c		*/
t_env_node	*find_node(t_env_lst *lst, char *key);
void		del_env_node(t_env_lst *lst, char *key);
int			env_node_update_or_create(t_env_lst *lst, char *key, char *value);

#endif
