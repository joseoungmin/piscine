# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyonpar <jiyonpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 11:48:24 by jiyonpar          #+#    #+#              #
#    Updated: 2022/12/10 19:27:27 by jiyonpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
CPPFLAGS		+=	-I$(LIBFT_D)$(INCS_D) -I$(INCS_D)
LDFLAGS			+=	-L$(LIBFT_D)
LDLIBS			=	-lft -lreadline
RM				=	rm -rf

LIBFT_D			=	./libft/
INCS_D			=	./include/
SRCS_D			=	./src/

OBJS_D			=	./.obj/
					
INC_FILE		=	minishell.h		\
					built_in.h		\
					executer.h		\
					ft_free.h		\
					minishell.h		\
					parse.h			\
					shell_lv_up.h	\
					crud.h			\
					ft_error.h		\
					ft_signal.h		\
					open_close.h	\
					print_gd.h		\
					structure.h

SRC_FILE		=	main.c				\
					check_cmdline.c		\
					open_close.c		\
					msplit.c			\
					split_quotes.c		\
					spt_split_quotes.c	\
					replace_dollar.c	\
					spt_replace_dollar.c\
					heredoc.c			\
					pair_to_quotes.c	\
					unit_crud.c			\
					envp_crud.c			\
					redir_crud.c		\
					spt_redir_crud.c	\
					ft_error.c			\
					ft_free.c			\
					print_gd.c			\
					signal.c			\
					ft_error_exit.c		\
					shell_lv_up.c		\
					check_built_in.c	\
					ft_echo.c			\
					ft_exit.c			\
					ft_pwd.c			\
					ft_cd.c				\
					ft_env.c			\
					ft_export.c			\
					ft_unset.c			\
					command_executer.c	\
					execute.c

OBJ_FILE		=	$(SRC_FILE:.c=.o)

LIBFT			=	$(LIBFT_D)libft.a
INCS			=	$(addprefix $(INCS_D), $(INC_FILE))
SRCS			=	$(addprefix $(SRCS_D), $(PARSE_FILE))
OBJS			=	$(addprefix $(OBJS_D), $(OBJ_FILE))

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJS)
					@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
					@echo "\033[K\033[32m $(NAME) is Ready ✅\033[0m"

bonus			:
					@make BONUS=1 all

$(LIBFT)		:	$(LIBFT_D)$(SRCS_D) $(LIBFT_D)$(INCS_D)
					@make -C $(LIBFT_D) all

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(INCS)
					@mkdir -p $(OBJS_D)
					@echo "\033[K\033[32m $(NAME) is Ready : $<\033[A"
					@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean			:
					@make -C $(LIBFT_D) clean
					@$(RM) $(MND_D)$(OBJS_D) $(BNS_D)$(OBJS_D)
					@echo "\033[36m    Remove Objects! 🗑\033[0m"

fclean			:	clean
					@make -C $(LIBFT_D) fclean
					@$(RM) $(NAME)
					@echo "\033[96m    Remove Program! 🗑\033[0m"

re				:	fclean
					@make all

.PHONY			:	all bonus clean fclean re
