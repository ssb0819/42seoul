RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = sl_game.c sl_main.c sl_map.c sl_map_check.c sl_utils.c
OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

BONUS_SRCS = sl_game_bonus.c sl_main_bonus.c sl_map_bonus.c sl_map_check_bonus.c sl_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(BONUS_OBJS))

GNL_SRCS = gnl/get_next_line2.c gnl/get_next_line_utils2.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY : all clean fclean re bonus

all : .sl_mandatory

bonus : .sl_bonus

.sl_mandatory : $(OBJ_FILES) $(GNL_OBJS) $(LIBFT)
	$(CC) $^ -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	touch $@

.sl_bonus : $(BONUS_OBJ_FILES) $(GNL_OBJS) $(LIBFT)
	$(CC) $^ -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	touch $@

clean :
	$(RM) $(OBJ_DIR) $(GNL_OBJS) .sl_mandatory .sl_bonus
	$(MAKE) -C $(LIBFT_DIR)/ clean

fclean : 
	$(MAKE) clean
	$(RM) $(NAME) $(LIBFT) .sl_mandatory .sl_bonus

re : 
	$(MAKE) fclean
	$(MAKE) all

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)/ bonus