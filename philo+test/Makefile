# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 00:06:03 by seojo             #+#    #+#              #
#    Updated: 2022/10/26 00:16:31 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRC_DIR	=	src/
SRCS	=	init routine print utils fork main time monitoring simul
M_SRCS	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCS)))
OBJS	=	$(M_SRCS:.c=.o)
CFAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
all		:	$(NAME)
$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean
