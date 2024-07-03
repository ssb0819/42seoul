CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread
RM = rm -rf

NAME = philosophers

SRCS = ph_main.c ph_fork.c ph_init.c ph_init_utils.c ph_print.c \
		ph_simulation.c ph_state.c ph_action.c
OBJS = $(SRCS:%.c=%.o)
UTIL_SRCS = $(addprefix utils/, ph_array.c ph_atoi.c)
UTIL_OBJS = $(UTIL_SRCS:%.c=%.o)
INC_DIR = includes

all : $(NAME)

$(NAME) : $(OBJS) $(UTIL_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $^

%.o : %.c $(INC_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	@$(RM) $(OBJS) $(UTIL_OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re