# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/10/03 10:16:44 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFTDIR	=	./libft
LIB_A		=	$(LIBFTDIR)/libft.a

SRCS	= 	push_swap.c			\
			init_parse.c		\
			push_swap_utils.c	\
			ft_ss.c				\
			ft_pp.c				\
			ft_rr.c				\
			ft_rrr.c			\
			ft_pivot.c			\
			ft_sort.c			\
			ft_sort_a_b.c		\
			ft_move_to.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) -I ./include -c -o $@ $<

$(NAME)	: 	$(OBJS) $(LIB_A)
			$(CC) $(CFLAGS) $^ -o $(NAME)

$(LIB_A) :
			make -C $(LIBFTDIR)

clean	:
			make -C $(LIBFTDIR) clean
			$(RM) $(OBJS)

fclean	:	clean
			make -C $(LIBFTDIR) fclean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean
