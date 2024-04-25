RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

B_CLIENT_SRC = client_bonus.c
B_SERVER_SRC = server_bonus.c
B_CLIENT_OBJ = $(B_CLIENT_SRC:.c=.o)
B_SERVER_OBJ = $(B_SERVER_SRC:.c=.o)

B_OTHER_SRCS = utils_bonus.c buffer_bonus.c
B_OTHER_OBJS = $(B_OTHER_SRCS:.c=.o)

B_HEADER = mt_bonus.h

all : .client .server

bonus : .client_bonus .server_bonus

clean :
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(B_CLIENT_OBJ) $(B_SERVER_OBJ) $(B_OTHER_OBJS)
	$(RM) .client .server .client_bonus .server_bonus
	$(MAKE) -C $(LIBFT_DIR)/ fclean

fclean : 
	$(MAKE) clean
	$(RM) client server

re : 
	$(MAKE) fclean
	$(MAKE) all

.client : $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CLIENT_OBJ) -Llibft -lft -o client
	touch $@

.server : $(SERVER_OBJ) $(LIBFT)
	$(CC) $(SERVER_OBJ) -Llibft -lft -o server
	touch $@


.client_bonus : $(B_CLIENT_OBJ) $(B_OTHER_OBJS) $(LIBFT) $(B_HEADER)
	$(CC) $(B_CLIENT_OBJ) $(B_OTHER_OBJS) -Llibft -lft -o client
	touch $@

.server_bonus : $(B_SERVER_OBJ) $(B_OTHER_OBJS) $(LIBFT) $(B_HEADER)
	$(CC) $(B_SERVER_OBJ) $(B_OTHER_OBJS) -Llibft -lft -o server
	touch $@

.PHONY : all bonus clean fclean re

%.o : %.c
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)/ bonus
