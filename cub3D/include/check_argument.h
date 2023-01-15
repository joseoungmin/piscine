/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:28:56 by seojo             #+#    #+#             */
/*   Updated: 2023/01/15 14:59:13 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGUMENT_H
# define CHECK_ARGUMENT_H
# include "libft.h"
# include "error.h"

void	check_map_extension(char *map_str);
void	check_argument(int ac, char **av);

#endif
