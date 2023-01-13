# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:55:56 by seojo             #+#    #+#              #
#    Updated: 2023/01/13 12:18:40 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	gcc
CXXFLAGS		=	-Wall -Wextra -Werror
DEPFLAGS		=	-MMD -MP -MF $(@:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
CPPFLAGS		=	-I$(INC_DIR)
RM				=	rm -rf
Q				=	@

INC_DIR			=	include/
SRC_DIR			=	src/
OBJ_DIR			=	.obj/
DEP_DIR			=	.dep/

PROG			=	" cub3D"
INC_FILE		=	#HEADERFILE1.hpp
SRC_FILE		=	main.c

OBJ_FILE		=	$(SRC_FILE:.c=.o)

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS			=	$(SRC_FILE:%.c=$(OBJ_DIR)%.o)
DEPS			=	$(SRC_FILE:%.c=$(DEP_DIR)%.d)

ifdef DEBUG
	CXXFLAGS	+=	-pedantic -g -fsanitize=address,undefined
endif
ifdef PRINT
	Q			=
endif

-include $(DEPS)
.DEFAULT_GOAL	=	all

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$Q$(CC) $(CXXFLAGS) -o $@ $(OBJS)
					@echo "\033[K\033[32m$(PROG) is Ready ✅\033[0m"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[K\033[32m$(PROG) is Ready : $<\033[A"
					$Q$(CC) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

clean			:
					$Q$(RM) $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[36mRemove Objects! 🗑\033[0m"

fclean			:	clean
					$Q$(RM) $(NAME)
					@echo "\033[96mRemove Program! 🗑\033[0m"

re				:	fclean
					@make all

.PHONY			:	all clean fclean re
