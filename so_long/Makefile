RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long
SRCS = mlx_test.c sl_debug.c sl_main.c sl_map.c sl_map_check.c sl_path_check.c sl_utils.c
OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

GNL_SRCS = gnl/get_next_line2.c gnl/get_next_line_utils2.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(OBJ_DIR) $(GNL_OBJS)

fclean : 
	$(RM) $(OBJ_DIR) $(GNL_OBJS) $(NAME) $(BONUS_NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

$(NAME) : $(OBJ_FILES) $(GNL_OBJS)
	$(CC) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
