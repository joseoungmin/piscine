# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 04:06:31 by seojo             #+#    #+#              #
#    Updated: 2022/09/13 17:49:11 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
LIBFTDIR	=	./libft
LIB_A		=	$(LIBFTDIR)/libft.a

SRCS	= 	pipex_bonus.c pipex_utils_bonus.c msplit_bonus.c free_ptr_bonus.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rcs

.c.o	:
			$(CC) $(CFLAGS) -I. -c -o $@ $<

all		:	$(NAME)

$(NAME)	: 	$(OBJS) $(LIB_A)
			$(CC) $(CFLAGS) libft/libft.a -I pipex.h $^ -o $(NAME)

$(LIB_A) :
			@make -C $(LIBFTDIR)

clean	:
			@make -C $(LIBFTDIR) clean
			@$(RM) $(OBJS) $(BNS_OBJS)

fclean	:	clean
			@make -C $(LIBFTDIR) fclean
			@$(RM) $(NAME)

re		:	fclean
			@make all

.PHONY	:	all clean fclean re
