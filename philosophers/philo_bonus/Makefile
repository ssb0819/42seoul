CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

NAME = philo_bonus

SRCS = ph_main_bonus.c ph_action_bonus.c ph_monitor_bonus.c ph_sem_bonus.c ph_print_bonus.c \
		ph_last_meal_bonus.c ph_simulation_bonus.c
OBJS = $(SRCS:%.c=%.o)
UTIL_SRCS = $(addprefix utils/, ph_atoi_bonus.c ph_utils.c)
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