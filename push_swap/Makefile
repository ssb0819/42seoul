NAME = push_swap
RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
SRCS = scrs/ps_main.c scrs/ps_list.c scrs/ps_utils.c scrs/ps_sort.c
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


TESTOBJS = scrs/ps_main.c scrs/ps_list.c scrs/ps_utils.c scrs/ps_sort.c test/debug.c
test_ps : ${TESTOBJS}
	cc -Wall -Wextra -Werror -g ${TESTOBJS} -o test_ps
tclean : fclean
	rm -f test_ps test/*.o