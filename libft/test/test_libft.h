#ifndef TEST_LIBFT_H
# define TEST_LIBFT_H

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

// part 1
void	test_isalpha();
void	test_isdigit();
void	test_isalnum();
void	test_isascii();
void	test_isprint();
void	test_strlen();
void	test_memset();
void	test_bzero();
void	test_memcpy();
void	test_memmove();
void	test_strlcpy();
void	test_strlcat();
void	test_toupper();
void	test_tolower();
void	test_strchr();
void	test_strrchr();
void	test_strncmp();
void	test_memchr();
void	test_memcmp();
void	test_strnstr();
void	test_atoi();
void	test_calloc();
void	test_strdup();
// part 2
void	test_substr();
void	test_strjoin();
void	test_strtrim();
void	test_split();
void	test_itoa();
void	test_strmapi();
void	test_striteri();
void	test_putchar_fd();
void	test_putstr_fd();
void	test_putendl_fd();
void	test_putnbr_fd();
// bonus_part
void	test_lstnew();
void	test_lstadd_front();
void	test_lstsize();
void	test_lstlast();
void	test_lstadd_back();
void	test_lstdelone();
void	test_lstclear();
void	test_lstiter();
void	test_lstmap();

void	print_content(void *content);
void	delete_content(void *content);
void	*change_content(void *content);

#endif
