/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:46 by seojo             #+#    #+#             */
/*   Updated: 2023/01/13 14:54:22 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
// 세분화 시켜서 에러 메세지 뽑기 
typedef enum e_map_err t_map_err

enum	e_map_err
{

}

void	print_map_argument_err(t_map_err err_num[5]) //enum 배열 사용가능?
{
	const char	map_err[10][20] = {
	};

	write(2, "Error\n", 6);
	write(2, map_err[err_num], ft_strlen(map_err[err_num]));
}
