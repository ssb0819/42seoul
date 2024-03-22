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
	-@cat _OUTPUT | ./checker_Mac `cat _ARG`
	@echo ""
	@echo "\033[0;32m===== Number of executed commands =====\033[0m"
	-@cat _OUTPUT | wc -l | tr -d ' '
	@echo ""
	@echo "\033[0;32m===== Cleaning up... =====\033[0m"
	-@$(MAKE) fclean &>/dev/null
	@echo "\033[0;32m===== DONE! =====\033[0m"