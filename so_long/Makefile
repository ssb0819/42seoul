RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long
SRCS = sl_debug.c sl_key_func.c sl_game_exe.c sl_main.c sl_map.c sl_map_check.c sl_path_check.c sl_utils.c
OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

GNL_SRCS = gnl/get_next_line2.c gnl/get_next_line_utils2.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT = libft/libft.a

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(OBJ_DIR) $(GNL_OBJS)
	$(MAKE) -C libft/ clean

fclean : 
	$(RM) $(OBJ_DIR) $(GNL_OBJS) $(NAME) $(BONUS_NAME)
	$(MAKE) -C libft/ fclean

re : 
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) -C libft/ re

$(NAME) : $(OBJ_FILES) $(GNL_OBJS) $(LIBFT)
	$(CC) $^ -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft/ all
