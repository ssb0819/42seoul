CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out

HEADERS = FragTrap.hpp ScavTrap.hpp ClapTrap.hpp
SRCS = FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re