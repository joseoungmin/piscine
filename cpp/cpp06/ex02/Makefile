NAME			=	a.out

CC				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
DEPFLAGS		=	-MMD -MP -MF $(@:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
CPPFLAGS		=	-I$(INC_DIR)
RM				=	rm -rf
Q				=	@

INC_DIR			=	include/
SRC_DIR			=	src/
OBJ_DIR			=	.obj/
DEP_DIR			=	.dep/

PROG			=	"Identify real type"

INC_FILE		=	Base.hpp

SRC_FILE		=	main.cpp	\
					Base.cpp

OBJ_FILE		=	$(SRC_FILE:.cpp=.o)

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS			=	$(SRC_FILE:%.cpp=$(OBJ_DIR)%.o)
DEPS			=	$(SRC_FILE:%.cpp=$(DEP_DIR)%.d)

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

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
					@mkdir -p $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[K\033[32m$(PROG) is Ready : $<\033[A"
					$Q$(CC) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

clean			:
					$Q$(RM) $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[36m  Remove Objects! 🗑\033[0m"

fclean			:	clean
					$Q$(RM) $(NAME)
					@echo "\033[96m  Remove Program! 🗑\033[0m"

re				:	fclean
					@make all

.PHONY			:	all clean fclean re
