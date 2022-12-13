/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:44:13 by seojo             #+#    #+#             */
/*   Updated: 2022/12/04 12:50:40 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef enum e_bool			t_bool;
typedef enum e_type			t_type;
typedef enum e_sig			t_sig;
typedef struct s_redir		t_redir;
typedef struct s_env_lst	t_env_lst;
typedef struct s_cmd_unit	t_cmd_unit;
typedef struct s_env_node	t_env_node;

enum e_bool
{
	FALSE,
	TRUE
};

enum e_type
{
	READ = 0,
	WRITE,
	APPEND,
	HEREDOC
};

enum e_sig
{
	GDSET,
	DEFAULT,
	IGNORE,
	HERE
};

enum e_access
{
	ROK,
	WOK,
	XOK,
	FOK
};

struct s_redir
{
	t_type	type;
	char	*filename;
	char	*doc;
	t_redir	*next;
};

struct s_cmd_unit
{
	char		**cmd;
	t_redir		*redir;
	t_cmd_unit	*next;
};

struct s_env_node
{
	t_env_node	*prev;
	t_env_node	*next;
	char		*key;
	char		*value;
};

struct s_env_lst
{
	t_env_node	*top;
	t_env_node	*bot;
};

#endif
