# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 00:06:03 by seojo             #+#    #+#              #
#    Updated: 2022/10/29 22:50:58 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

SRC_DIR	=	src/
INC_DIR	=	include/

SRCS	=	init routine print utils main time monitoring simul

M_SRCS	=	$(addsuffix _bonus.c, $(addprefix $(SRC_DIR), $(SRCS)))

OBJS	=	$(M_SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

.c.o	:
			$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean
