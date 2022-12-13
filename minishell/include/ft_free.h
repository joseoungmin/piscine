/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:45:03 by seojo             #+#    #+#             */
/*   Updated: 2022/12/06 18:14:16 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H
# include <stdlib.h>

void	ft_free(char *ptr);
char	**ft_free_dptr(char **s, int i);

#endif
