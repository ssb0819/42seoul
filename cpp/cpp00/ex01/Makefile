CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors
NAME = phonebook

HEADERS = contact.hpp phonebook.hpp
SRCS = contact.cpp phonebook.cpp
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