RM = rm -f
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rsc

NAME = libft.a
OBJS = ft_isalpha.o \
ft_isdigit.o \
ft_isalnum.o \
ft_isascii.o \
ft_isprint.o \
ft_strlen.o \
ft_memset.o \
ft_bzero.o \
ft_memcpy.o \
ft_memmove.o \
ft_strlcpy.o \
ft_strlcat.o \
ft_toupper.o \
ft_tolower.o \
ft_strchr.o \
ft_strrchr.o \
ft_strncmp.o \
ft_memchr.o \
ft_memcmp.o \
ft_strnstr.o \
ft_atoi.o \
ft_calloc.o \
ft_strdup.o \
ft_substr.o \
ft_strjoin.o
# ft_strtrim.o
# ft_split.o
# ft_itoa.o
# ft_strmapi.o
# ft_striteri.o
# ft_putchar_fd.o
# ft_putstr_fd.o
# ft_putendl_fd.o
# ft_putnbr_fd.o

.PHONY: all clean fclean re
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: 
	$(RM) $(OBJS) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

test: test/test_libft.c $(NAME)
	cc -o test/test_libft test/test_libft.c -L. -l ft

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
