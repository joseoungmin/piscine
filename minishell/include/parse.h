/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:26:54 by seojo             #+#    #+#             */
/*   Updated: 2022/12/09 20:19:55 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "structure.h"
# include "crud.h"
# include "libft.h"
# include "ft_error.h"
# include "ft_free.h"
# include <stdio.h>
# include <readline/readline.h>

/*		check_cmdline		*/
int		check_syntax(char **cmd, int *exit_stat);
int		check_pipe(char **cmd);
int		check_blank(char *cmd);
void	pass_quotes(char *cmd, int *i);

/*		pair_to_quotes.c	*/
char	*pair_to_quotes(char *s);

/*		split_quotes.c		*/
char	**split_quotes(t_env_lst *lst, char *s, char c, int exit_stat);
size_t	count_words(t_env_lst *lst, char *str, char c, int exit_stat);

/*		spt_split_quotes.c	*/
int		spt_split_quotes(char **buf, char *s, char c, int *words_idx);
char	**buf_alloc(t_env_lst *lst, char *s, char c, int exit_stat);
void	len_and_exit_stat(int (*len_stat)[2], char *s, char *tmp, \
		int exit_stat);
int		return_env_len(char *dollar);

/*		msplit.c			*/
char	**msplit(char const *s, char c);

/*		replace_dollar.c	*/
char	*replace_dollar(t_env_lst *lst, char *str, int exit_stat);

/*		stp_replace_dollar.c	*/

char	*add_home_path(char	*cmd);

#endif
