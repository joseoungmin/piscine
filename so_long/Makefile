# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/10/07 17:18:37 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIB_A 		=	libft/libft.a
MLX_A 		=	mlx/libmlx.a
LIB_DIR 	=	libft/
MLX_DIR		=	mlx/
INC_DIR		=	include/
SRC_DIR		=	mandatory/

SRCS		=	so_long			\
				draw_map		\
				map_check		\
				move			\
				so_long_utils

M_SRCS		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCS)))

OBJS		= 	$(M_SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I./include
LDFLAGS 	=	-L$(LIB_DIR) -L$(MLX_DIR)
LDLIBS		=	-lft -lmlx -framework OpenGL -framework AppKit

all			:	$(NAME)

$(NAME)		: 	$(OBJS) $(LIB_A) $(MLX_A)
				@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) 
				@echo "so_long OK!"

%.o			:	%.c $(INC_DIR)
				@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(LIB_A)	:	$(LIB_DIR)
				@make -s -C $(LIB_DIR)

$(MLX_A)	:	$(MLX_DIR)
				@make -s -C $(MLX_DIR) 2> /dev/null
				@echo "    mlx OK!"

clean		:
				@make -s -C $(LIB_DIR) clean
				@make -s -C $(MLX_DIR) clean
				@$(RM) $(OBJS)
				@echo "  clean OK!"

fclean		:	clean
				@make -s -C $(LIB_DIR) fclean
				@$(RM) $(NAME)
				@echo " fclean OK!"

re			:	fclean
				@make all

.PHONY		:	all clean fclean
