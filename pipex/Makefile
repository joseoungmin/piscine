# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 04:06:31 by seojo             #+#    #+#              #
#    Updated: 2022/09/11 21:07:39 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
LIBFTDIR	=	./libft
LIB_A		=	$(LIBFTDIR)/libft.a

SRCS	= 	pipex.c pipex_utils.c msplit.c free_ptr.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rcs

.c.o	:
			arch -x86_64 $(CC) $(CFLAGS) -I. -c -o $@ $<

all		:	$(NAME)

$(NAME)	: 	$(OBJS) $(LIB_A)
			arch -x86_64 $(CC) $(CFLAGS) libft/libft.a -I pipex.h $^ -o $(NAME)

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
