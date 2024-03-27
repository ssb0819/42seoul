RM = rm -rf
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
SRCS = ps_init.c ps_list.c ps_list2.c ps_operation.c ps_quick_sort.c ps_sort_stack.c ps_utils.c
OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))
MAIN_OBJ = objs/ps_main.o
MAIN_SRC = ps_main.c

BONUS_NAME = checker
BONUS_SRCS = ps_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(BONUS_OBJS))

GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(OBJ_DIR) $(GNL_OBJS)

fclean : 
	$(RM) $(OBJ_DIR) $(GNL_OBJS) $(NAME) $(BONUS_NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

bonus : $(BONUS_NAME)

$(NAME) : $(OBJ_FILES) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(MAIN_OBJ) : $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME) : $(OBJ_FILES) $(BONUS_OBJ_FILES) $(GNL_OBJS)
	$(CC) $(CFLAGS) $^ -o $@
