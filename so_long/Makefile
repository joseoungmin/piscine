# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/10/07 05:50:13 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIB_DIR 	=	./libft/
LIB_A = ./libft/libft.a
MLX_DIR		=	./mlx/

SRCS	=	so_long	\
			draw_map

M_SRCS	=	$(addsuffix .c, $(addprefix mandatory/, $(SRCS)))

OBJS	= 	$(M_SRCS:.c=.o)





CC		=	arch -x86_64 gcc





CFLAGS	= 	-Wall -Wextra -Werror
CFLAGS +=	-g -fsanitize=address

CPPFLAGS = -I ./include
LDFLAGS =  -L $(LIB_DIR) -L $(MLX_DIR)
LDFLAGS += -fsanitize=address
LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(NAME)	: 	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) 

$(OBJS) : $(LIB_A)

$(LIB_A) : $(LIB_DIR)

$(LIB_DIR):
			make -C $(LIB_DIR)

clean	:
			make -C $(LIB_DIR) clean
			make -C $(MLX_DIR) clean
			$(RM) $(OBJS) $(B_OBJS)

fclean	:	clean
			make -C $(LIB_DIR) fclean
			$(RM) $(NAME) $(B_NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean $(LIB_DIR)
