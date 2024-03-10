NAME = push_swap
RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
SRCS = scrs/main.c scrs/list.c
OBJS = ${SRCS:.c=.o}

.PHONY : all clean fclean re

all : ${NAME}

clean :
	$(RM) $(OBJS) 

fclean : 
	$(RM) $(OBJS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

TESTOBJS = test/test.o scrs/list.o
test : all test ${TESTOBJS}
	cc -Wall -Wextra -Werror ${TESTOBJS} -o test_push_swap
aclean : fclean
	rm -f test_push_swap test/*.o