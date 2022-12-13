/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:34:27 by seojo             #+#    #+#             */
/*   Updated: 2022/12/10 19:35:27 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_readline(void)
{
	char	*command;

	command = readline("GDshell$ ");
	if (!command)
		ctrl_exit();
	if (*command == '\0')
	{
		ft_free(command);
		return (NULL);
	}
	return (command);
}

void	gd_shell(t_env_lst *env_lst, int exit_stat)
{
	char		*command;
	char		*pair_quotes;
	t_cmd_unit	*unit;

	shell_lv_up(env_lst);
	sig_handler(GDSET, GDSET);
	while (1)
	{
		command = ft_readline();
		if (command == NULL)
			continue ;
		pair_quotes = pair_to_quotes(command);
		if (pair_quotes != NULL)
			add_history(pair_quotes);
		if (check_syntax(&pair_quotes, &exit_stat))
			continue ;
		unit = split_pipe_cmd(env_lst, pair_quotes, &exit_stat);
		if (unit == NULL)
			continue ;
		if (check_heredoc(unit) == 0)
			command_executer(env_lst, unit, &exit_stat);
		unlink_docfile();
		ft_free(pair_quotes);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env_lst	*env_lst;

	if (argc > 1 && argv)
	{
		printf("Run without any arguments.\n");
		return (1);
	}
	env_lst = envp_cpy(envp);
	if (!env_lst)
		error_cmd("malloc", strerror(12), 0);
	print_gd();
	set_termios();
	gd_shell(env_lst, 0);
	return (0);
}
