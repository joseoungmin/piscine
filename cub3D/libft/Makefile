# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:39:36 by jiyonpar          #+#    #+#              #
#    Updated: 2023/01/13 13:26:08 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I$(INCS_DIR)
RM				=	rm -rf
ARFLAGS			=	rcs

INCS_DIR		=	./include/
SRCS_DIR		=	./src/
OBJS_DIR		=	./.obj/

PART1_SRCS		=	ft_isalpha.c	\
					ft_isdigit.c	\
					ft_isalnum.c	\
					ft_isascii.c	\
					ft_isprint.c	\
					ft_isspace.c	\
					ft_strlen.c		\
					ft_memset.c		\
					ft_bzero.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_strlcpy.c	\
					ft_strlcat.c	\
					ft_toupper.c	\
					ft_tolower.c	\
					ft_strchr.c		\
					ft_strrchr.c	\
					ft_strncmp.c	\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_strnstr.c	\
					ft_atoi.c		\
					ft_calloc.c		\
					ft_strdup.c
PART2_SRCS		=	ft_substr.c		\
					ft_strjoin.c	\
					ft_strtrim.c	\
					ft_split.c		\
					ft_itoa.c		\
					ft_strmapi.c	\
					ft_striteri.c	\
					ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c
BONUS_SRCS		=	ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstclear.c		\
					ft_lstiter.c		\
					ft_lstmap.c
GNL_SRCS		=	get_next_line.c			\
					get_next_line_utils.c

SRC_FILES		=	$(PART1_SRCS)	\
					$(PART2_SRCS)	\
					$(BONUS_SRCS)	\
					$(GNL_SRCS)
OBJ_FILES		=	$(SRC_FILES:.c=.o)
SRCS			=	$(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJ_FILES))

all				:	$(NAME)

$(NAME)			:	$(OBJS_DIR) $(OBJS)
					@$(AR) $(ARFLAGS) $@ $(OBJS)
					@echo "\033[K\033[33m   libft is Ready ✅\033[0m"

$(OBJS_DIR)		:
					@mkdir -p $@

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c $(INCS_DIR)
					@echo "\033[K\033[33m $(NAME) is Ready: $<\033[A"
					@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean			:
					@$(RM) $(OBJS_DIR)

fclean			:	clean
					@$(RM) $(NAME)

re				:	fclean
					@make all

.PHONY			:	all clean fclean re
