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
GNL_OBJ_FILES = $(GNL_OBJS)

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

$(BONUS_NAME) : $(OBJ_FILES) $(BONUS_OBJ_FILES) $(GNL_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

RANDCNT = 100

create:
	-@jot -r -s " " $(RANDCNT) -2147483648 2147483647 > _ARG

pstest:
	@echo "You can change the number of random numbers by \033[1mpassing RANDCNT=n as an argument to make test.\033[0m"
	@echo "Default value is 100, \033[1mcurrent value is $(RANDCNT).\033[0m\n"
	@echo "\033[0;32m===== Compiling test===== \033[0m"
	-@$(MAKE) -j &>/dev/null
	@echo "Compile completed"
	-@$(MAKE) create
	@echo ""
	@echo "\033[0;33m===== Running test =====\033[0m"
	-@./$(NAME) `cat _ARG` > _OUTPUT
	@echo "\033[0;32m===== Test completed =====\033[0m"
	@echo ""
	@echo "\033[0;33m===== Checking if the output is sorted =====\033[0m"
	-@cat _OUTPUT | ./checker `cat _ARG`
	@echo ""
	@echo "\033[0;32m===== Number of executed commands =====\033[0m"
	-@cat _OUTPUT | wc -l | tr -d ' '
	@echo ""
	@echo "\033[0;32m===== Cleaning up... =====\033[0m"
	-@$(MAKE) clean &>/dev/null
	@echo "\033[0;32m===== DONE! =====\033[0m"