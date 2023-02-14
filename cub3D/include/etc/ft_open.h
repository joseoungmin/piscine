/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:49:18 by seojo             #+#    #+#             */
/*   Updated: 2023/01/14 16:53:07 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPEN_H
# define FT_OPEN_H
# include "error.h"
# include <fcntl.h>
# include <sys/errno.h>

int	ft_open(char *filename);

#endif
