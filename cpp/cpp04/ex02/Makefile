CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out

HEADERS = AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp
SRCS = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
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