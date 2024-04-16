/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:09:55 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 21:34:03 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "gnl/get_next_line2.h"
# include "libft/libft.h"

# define TILE_SIZE 64

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 2560
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1440
# endif

# define ERR_MSG "Error\nSystem Error "
# define MAP_ERR_MSG "Error\nInvalid map file\n"
# define MV_CNT_MSG "movement count : "
# define BLACK_TRGB 0x00000000
# define BLUE_TRGB 0x000000FF

# define MAP_EXTENSION ".ber"

# define COLLTB_PATH "./assets/collectible.xpm"
# define EXIT_PATH "./assets/exit.xpm"
# define PLAYER_PATH "./assets/player.xpm"
# define BKGRND_PATH "./assets/background.xpm"
# define WALL_PATH "./assets/wall.xpm"

# define COLLTB 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define BLANK '0'
# define WALL '1'
# define VISITED 'V'

typedef struct s_map_info
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		colltb_count;
}				t_map_info;

typedef struct s_param
{
	void			*mlx;
	void			*win;
	t_map_info		*map_info;
	void			**images;
	unsigned int	move_count;
}				t_param;

typedef enum e_components
{
	C,
	E,
	P,
	B,
	W
}			t_components;

typedef enum e_err_types
{
	SYSTEM_ERR,
	RUNTIME_ERR
}	t_err_types;

typedef enum e_events
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
}				t_events;

typedef enum e_keycodes
{
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126
}			t_keycodes;

/* sl_map_bonus.c */
t_list		*read_map_file(int fd, t_map_info *map_info);
void		set_map_size(t_list *read_lines, t_map_info *map_info);
void		set_map(t_list *read_lines, t_map_info *map_info);
void		set_other_info(t_map_info *map_info);
char		**duplicate_map(t_map_info *map_info);

/* sl_map_check_bonus.c */
void		check_extension(char *file_name);
void		check_wall(t_map_info *map_info);
void		check_next_path(char **map, int *counts, int x, int y);
void		check_component(t_map_info *map_info, int *counts, int x, int y);

/* sl_game_bonus.c */
void		**upload_tile_imgs(void *mlx);
void		init_window(t_param *param);
void		print_tile(t_param *param, char component, int x, int y);
int			exe_on_key_down(int keycode, t_param *param);
void		move_character(t_param *param, int next_x, int next_y);

/* sl_utils_bonus.c */
int			exit_game(t_param *param);
void		exit_on_error(t_err_types e_type, char *err_msg);
int			sl_strcmp(const char *s1, const char *s2);
void		print_move_count(t_param *param);
void		free_2d_array(char **array, int len);

#endif