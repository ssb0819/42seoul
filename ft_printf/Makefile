RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

NAME = libftprintf.a

OBJS = ft_printf.o ft_print_param.o ft_print_utils.o


.PHONY: all bonus clean fclean re

all : ${NAME}

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 
	$(RM) $(OBJS) $(BONUS_OBJS) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
