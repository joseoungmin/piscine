# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/10/06 14:51:50 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIB_DIR 	=	./libft/
MLX_DIR		=	./mlx/

SRCS	=	so_long

M_SRCS	=	$(addsuffix .c, $(addprefix mandatory/, $(SRCS)))

OBJS	= 	$(M_SRCS:.c=.o)

CC		=	arch -x86_64 gcc
CFLAGS	= 	-Wall -Wextra -Werror

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) -I ./include -c -o $@ $<

$(NAME)	: 	$(OBJS)
			arch -x86_64 make -C $(LIB_DIR)
			arch -x86_64 make -C $(MLX_DIR)
			$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -I ./include/ -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

clean	:
			make -C $(LIB_DIR) clean
			make -C $(MLX_DIR) clean
			$(RM) $(OBJS) $(B_OBJS)

fclean	:	clean
			make -C $(LIB_DIR) fclean
			$(RM) $(NAME) $(B_NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean
