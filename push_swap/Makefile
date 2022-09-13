# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/09/02 10:58:55 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	= 	ft_memset.c		\
BNS_SRCS=	ft_lstnew.c			\

OBJS	= 	$(SRCS:.c=.o)

BNS_OBJS=	$(BNS_SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rcs

all		:	$(NAME)

bonus	:	$(NAME)

$(NAME)	: 	$(OBJS) $(if $(filter bonus, $(MAKECMDGOALS)), $(BNS_OBJS))
			$(AR) $@ $^

.c.o	:
			$(CC) $(CFLAGS) -I. -c -o $@ $<

clean	:
			$(RM) $(OBJS) $(BNS_OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean re bonus
