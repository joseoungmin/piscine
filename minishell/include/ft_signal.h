/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:35:28 by seojo             #+#    #+#             */
/*   Updated: 2022/12/04 13:01:35 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H
# include "structure.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

void	set_termios(void);
void	sig_handler(t_sig intnum, t_sig quitnum);
void	ctrl_exit(void);

#endif
