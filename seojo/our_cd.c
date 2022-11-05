/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:10:56 by seojo             #+#    #+#             */
/*   Updated: 2022/11/05 14:00:03 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//# include "../libft/libft.h"
//# include "structs.h"
//# include "alloc_token.h"
//# include "unset.h"

typedef struct s_mini
{
	char	**envp;
	char	**av;
	int		ac;
}				t_mini;

int	main(int ac, char **av, char **envp)
{
	t_mini	mini;
//	char	*line;
//	char	**cpenv;
	
	dup2(STDIN, 100);
	dup2(STDOUT, 101);
	ac = 1;
	//copy envp
	//set_signal();
	print_gd();
	/*while ((line = readline("GDShell $ ")))
	{
		if (*line != '\0')
			add_history(line);
	}
	*/
	mini.envp = envp;
	mini.av = av;
	mini.ac = ac;
	return (0);
}
