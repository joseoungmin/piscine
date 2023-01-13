# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:55:56 by seojo             #+#    #+#              #
#    Updated: 2023/01/13 13:27:01 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	gcc
CXXFLAGS		=	-Wall -Wextra -Werror
DEPFLAGS		=	-MMD -MP -MF $(@:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
CPPFLAGS		=	-I$(INC_DIR) -I$(LIBFT_DIR)$(INC_DIR)
RM				=	rm -rf
Q				=	@

LIBFT_DIR		=	libft/
MLX_DIR			=	mlx/
INC_DIR			=	include/
SRC_DIR			=	src/
OBJ_DIR			=	.obj/
DEP_DIR			=	.dep/

PROG			=	"cub3D"
SRC_FILE		=	main.c

OBJ_FILE		=	$(SRC_FILE:.c=.o)

LIBFT			=	$(LIBFT_DIR)libft.a
MLX				=	$(MLX_DIR)libmlx.a
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS			=	$(SRC_FILE:%.c=$(OBJ_DIR)%.o)
DEPS			=	$(SRC_FILE:%.c=$(DEP_DIR)%.d)

LDLIBS			=	mlx/libmlx.a -framework OpenGL -framework AppKit

ifdef DEBUG
	CXXFLAGS	+=	-pedantic -g -fsanitize=address,undefined
endif
ifdef PRINT
	Q			=
endif

-include $(DEPS)
.DEFAULT_GOAL	=	all

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(MLX) $(OBJS)
					$Q$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDLIBS)
					@echo "\033[K\033[32m   $(PROG) is Ready ✅\033[0m"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[K\033[32m   $(PROG) is Ready : $<\033[A"
					$Q$(CC) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBFT)		:	$(LIBFT_DIR)$(SRC_DIR) $(LIBFT_DIR)$(INC_DIR)
					@make -C $(LIBFT_DIR) all

$(MLX)			:	$(MLX_DIR)
					@make -s -C $(MLX_DIR) 2> /dev/null
					@echo "\033[K\033[33m     mlx is Ready ✅\033[0m"

clean			:
					$Qmake -C $(LIBFT_DIR) clean
					$Qmake -s -C $(MLX_DIR) clean
					$Q$(RM) $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[36m  Remove Objects! 🗑\033[0m"

fclean			:	clean
					$Qmake -C $(LIBFT_DIR) fclean
					$Q$(RM) $(NAME)
					@echo "\033[96m  Remove Program! 🗑\033[0m"

re				:	fclean
					@make all

.PHONY			:	all clean fclean re
