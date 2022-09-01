# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 14:39:42 by seojo             #+#    #+#              #
#    Updated: 2022/08/16 19:06:17 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFTDIR	=	./libft
LIBFTFILE	=	libft.a

SRCS	= 	ft_printf.c			\
			ft_print_hex.c		\
			ft_print_nbr.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rcs

all		:	$(NAME)

$(NAME)	: 	$(OBJS)
			make -C $(LIBFTDIR)
			cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
			$(AR) $@ $^

clean	:
			make -C $(LIBFTDIR) clean
			$(RM) $(OBJS) $(BNS_OBJS)

fclean	:	clean
			make -C $(LIBFTDIR) fclean
			$(RM) $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean re
