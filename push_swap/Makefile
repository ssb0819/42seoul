NAME = push_swap
RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror -g
SRCS_DIR = scrs
SRCS = debug.c ps_list.c ps_list2.c ps_main.c ps_operation.c ps_quick_sort.c ps_sort_stack.c
OBJ_DIR = objs
OBJS = ${SRCS_DIR}/${SRCS:.c=.o}
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

.PHONY : all clean fclean re

all : ${NAME}

clean :
	$(RM) $(OBJS_FILES) 

fclean : 
	$(RM) -r ${OBJ_DIR} $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

$(NAME) : $(OBJ_FILES)
	${CC} ${CFLAGS} $^ -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : ${SRCS_DIR}/%.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@
