NAME = push_swap
RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror -g
SRCS = debug.c ps_divide.c ps_list.c ps_list2.c ps_main.c ps_operation.c ps_quick_sort.c ps_sort_stack.c
OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

.PHONY : all clean fclean re

all : $(NAME)

clean :
	$(RM) $(OBJS_FILES) 

fclean : 
	$(RM) -r $(OBJ_DIR) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
