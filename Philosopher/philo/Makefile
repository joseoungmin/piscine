# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 00:06:03 by seojo             #+#    #+#              #
#    Updated: 2022/11/23 18:32:50 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRC_DIR	=	src/

SRCS	=	init routine print utils main time monitoring simul

M_SRCS	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCS)))

OBJS	=	$(M_SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror #-O3

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

.c.o	:
			$(CC) $(CFLAGS) -c -o $@ $<

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean
