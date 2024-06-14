CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread
RM = rm -rf

NAME = philosopher

SRC = main.c
OBJS = $(SRC:%.c=%.o)
HEADER = philosopher.h

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(LDFALGS) -o $(NAME) $(LIBFT) $^

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re