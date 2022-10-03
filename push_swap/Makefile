# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:58:47 by seojo             #+#    #+#              #
#    Updated: 2022/10/03 14:34:45 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
B_NAME		=	checker
LIBFTDIR	=	./libft
LIB_A		=	$(LIBFTDIR)/libft.a

SRCS	=	push_swap			\
			init_parse			\
			push_swap_utils		\
			ft_ss				\
			ft_pp				\
			ft_rr				\
			ft_rrr				\
			ft_pivot			\
			ft_sort				\
			ft_sort_a_b			\
			ft_move_to

SRCS_B	=	push_swap		\
			push_swap_utils	\
			init_parse		\
			ft_ss			\
			ft_pp			\
			ft_rr			\
			ft_rrr

M_SRCS	=	$(addsuffix .c, $(addprefix mandatory/, $(SRCS)))

B_SRCS	=	$(addsuffix _bonus.c, $(addprefix bonus/, $(SRCS_B)))

OBJS	= 	$(M_SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) -I ./include -c -o $@ $<

$(NAME)	: 	$(OBJS) $(LIB_A)
			$(CC) $(CFLAGS) $^ libft/libft.a -o $(NAME)

$(B_NAME)	:	$(B_OBJS) $(LIB_A)
				$(CC) $(CFLAGS) $^ libft/libft.a -o $(B_NAME)

$(LIB_A) :
			make -C $(LIBFTDIR)

clean	:
			make -C $(LIBFTDIR) clean
			$(RM) $(OBJS) $(B_OBJS)

fclean	:	clean
			make -C $(LIBFTDIR) fclean
			$(RM) $(NAME) $(B_NAME)

re		:	fclean
			make all

bonus	:	$(B_NAME)

.PHONY	:	all clean fclean
