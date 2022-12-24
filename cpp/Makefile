NAME			=	PROGRAM_NAME
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS		=	-I$(INCS_D)
RM				=	rm -rf
INCS_D			=	./include/
SRCS_D			=	./src/
OBJS_D			=	./.obj/
PRINT			=	"PRINT_STR"
INC_FILE		=	HEADERFILE.hpp
SRC_FILE		=	SOURCEFILE1.cpp \
					SOURCEFILE2.cpp \
					SOURCEFILE3.cpp
OBJ_FILE		=	$(SRC_FILE:.cpp=.o)
INCS			=	$(addprefix $(INCS_D), $(INC_FILE))
SRCS			=	$(addprefix $(SRCS_D), $(SRC_FILE))
OBJS			=	$(addprefix $(OBJS_D), $(OBJ_FILE))
all				:	$(NAME)
$(NAME)         :	$(OBJS)
					@$(CC) $(CFLAGS) -o $@ $(OBJS)
					@echo "\033[K\033[32m $(PRINT) is Ready :white_check_mark:\033[0m"

$(OBJS_D)%.o	:   $(SRCS_D)%.cpp $(INCS)
					@mkdir -p $(OBJS_D)
					@echo "\033[K\033[32m $(PRINT) is Ready : $<\033[A"
					@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean			:
					@$(RM) $(OBJS_D)
					@echo "\033[36m  Remove Objects! :wastebasket:\033[0m"
fclean			:	clean
					@$(RM) $(NAME)
					@echo "\033[96m  Remove Program! :wastebasket:\033[0m"
re				:	fclean
					@make all
.PHONY			:	all clean fclean re
