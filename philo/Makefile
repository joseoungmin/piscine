# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/10/07 23:23:45 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
LIB_A 		=	libft/libft.a
LIB_DIR 	=	libft/
INC_DIR		=	include/
SRC_DIR		=	src/

SRCS		=	philo

M_SRCS		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCS)))

OBJS		= 	$(M_SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I./include
LDFLAGS 	=	-L$(LIB_DIR)
LDLIBS		=	-lft

all			:	$(NAME)

$(NAME)		: 	$(OBJS) $(LIB_A)
				@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) 
				@echo "so_long OK!"

%.o			:	%.c $(INC_DIR)
				@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(LIB_A)	:	$(LIB_DIR)
				@make -s -C $(LIB_DIR)

clean		:
				@make -s -C $(LIB_DIR) clean
				@$(RM) $(OBJS)
				@echo "  clean OK!"

fclean		:	clean
				@make -s -C $(LIB_DIR) fclean
				@$(RM) $(NAME)
				@echo " fclean OK!"

re			:	fclean
				@make all

.PHONY		:	all clean fclean
