# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 04:06:31 by seojo             #+#    #+#              #
#    Updated: 2022/09/15 09:37:56 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
LIBFTDIR	=	./libft
LIB_A		=	$(LIBFTDIR)/libft.a

SRCS	= 	$(addprefix mandatory/, \
			pipex.c \
			pipex_utils.c \
			msplit.c \
			pipex_ft_func.c)

B_SRCS	=	$(addprefix pipex_bonus/, \
			pipex_bonus.c	\
			pipex_utils_bonus.c	\
			msplit_bonus.c	\
			pipex_ft_func_bonus.c)

OBJS	= 	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rcs


ifdef BONUS
		OBJECTS = $(B_OBJS)
else
		OBJECTS = $(OBJS)
endif

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) -I ./include -c -o $@ $<

$(NAME)	: 	$(OBJECTS) $(LIB_A)
			$(CC) $(CFLAGS) libft/libft.a $^ -o $(NAME)

$(LIB_A) :
			make -C $(LIBFTDIR)

clean	:
			make -C $(LIBFTDIR) clean
			$(RM) $(OBJS) $(B_OBJS)

fclean	:	clean
			make -C $(LIBFTDIR) fclean
			$(RM) $(NAME)

re		:	fclean
			make all
bonus :
			make BONUS=1

.PHONY	:	all clean fclean re
