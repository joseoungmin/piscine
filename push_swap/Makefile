# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/09/19 20:16:17 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	= 	push_swap.c		\

OBJS	= 	$(SRCS:.c=.o)

BNS_OBJS=	$(BNS_SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rcs

all		:	$(NAME)

$(NAME)	: 	$(OBJS)
			$(CC) $(CFLAGS) $@ $^

.c.o	:
			$(CC) $(CFLAGS) -c -o $@ $<

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean
