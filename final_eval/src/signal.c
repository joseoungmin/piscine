/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:28:36 by seojo             #+#    #+#             */
/*   Updated: 2022/12/05 14:52:41 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"

void	set_termios(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	sig_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		exit(1);
	}
}

static void	sig_coustom(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		if (rl_on_new_line() == -1)
			exit(1);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
		rl_redisplay();
}

void	sig_handler(t_sig intnum, t_sig quitnum)
{
	if (intnum == HERE)
		signal(SIGINT, sig_heredoc);
	if (intnum == GDSET)
		signal(SIGINT, sig_coustom);
	if (intnum == DEFAULT)
		signal(SIGINT, SIG_DFL);
	if (intnum == IGNORE)
		signal(SIGINT, SIG_IGN);
	if (quitnum == GDSET)
		signal(SIGQUIT, sig_coustom);
	if (quitnum == DEFAULT)
		signal(SIGQUIT, SIG_DFL);
	if (quitnum == IGNORE)
		signal(SIGQUIT, SIG_IGN);
}

void	ctrl_exit(void)
{
	printf("%s%sexit\n", "\033[1A", "\033[9C");
	exit(0);
}
