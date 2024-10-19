CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harlFilter

HEADERS = Harl.hpp
SRCS = Harl.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re