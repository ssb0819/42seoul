RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SRC = mt_client.c
SERVER_SRC = mt_server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

B_CLIENT_SRC = mt_client_bonus.c
B_SERVER_SRC = mt_server_bonus.c
B_CLIENT_OBJ = $(B_CLIENT_SRC:.c=.o)
B_SERVER_OBJ = $(B_SERVER_SRC:.c=.o)

OTHER_SRCS = mt_utils_bonus.c
OTHER_OBJS = $(OTHER_SRCS:.c=.o)

BONUS_HEADER = mt_bonus.h

all : .mandatory

bonus : .bonus

clean :
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(B_CLIENT_OBJ) $(B_SERVER_OBJ) $(OTHER_OBJS) .mandatory .bonus
	$(MAKE) -C $(LIBFT_DIR)/ clean

fclean : 
	$(MAKE) clean
	$(RM) client server $(LIBFT)

re : 
	$(MAKE) fclean
	$(MAKE) all

.mandatory : $(CLIENT_OBJ) $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CLIENT_OBJ) -Llibft -lft -o client
	$(CC) $(SERVER_OBJ) -Llibft -lft -o server
	touch $@

.bonus : $(B_CLIENT_OBJ) $(B_SERVER_OBJ) $(OTHER_OBJS) $(LIBFT) $(BONUS_HEADER)
	$(CC) $(B_CLIENT_OBJ) $(OTHER_OBJS) -Llibft -lft -o client
	$(CC) $(B_SERVER_OBJ) $(OTHER_OBJS) -Llibft -lft -o server
	touch $@

.PHONY : all bonus clean fclean re

%.o : %.c
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)/ bonus
