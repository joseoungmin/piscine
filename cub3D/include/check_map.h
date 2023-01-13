/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:58:48 by seojo             #+#    #+#             */
/*   Updated: 2023/01/13 20:25:31 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include "libft.h"
# include "error.h"
# include <fcntl.h>
# include <sys/errno.h>

typedef enum e_map_err	t_map_err;
typedef struct s_map	t_map;

enum e_map_err
{
	FALSE = 0,
	TRUE = 1,
	RED = 0,
	GREEN = 1,
	BLUE = 2,
};

struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		ceiling;
	char	**map;
};

// 각 방향당 파일 하나씩 있는지,  파일명.확장자, 존재유무, 권한
// 색상 초과-미만, 어떤 색상이 없는지 있는지.
// error 출력 이후에 다른 없는 부분들까지 출력

void	print_map_argument_err(t_map_err err_num);
t_map	*check_and_return_map(char *map_file);

#endif
