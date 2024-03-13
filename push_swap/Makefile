NAME = push_swap
RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
SRCS = scrs/main.c scrs/list.c scrs/utils.c
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


TESTOBJS = scrs/main.c scrs/list.c scrs/utils.c test/debug.c
test_ps : ${TESTOBJS}
	cc -Wall -Wextra -Werror -g ${TESTOBJS} -o test_ps
tclean : fclean
	rm -f test_ps test/*.o