/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:09:55 by subson            #+#    #+#             */
/*   Updated: 2024/04/02 23:50:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "gnl/get_next_line2.h"

# define ERR_MSG "Error\n"
# define MAP_ERR_MSG "Error\nInvalid map file\n"

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
	int		start_x;
	int		start_y;
	int		colltb_count;
}	t_map_info;

typedef enum e_components
{
	C,
	E,
	P,
	B,
	W
}	t_components;

typedef enum e_err_types
{
	SYSTEM_ERR,
	RUNTIME_ERR
}	t_err_types;

/* sl_main.c */
t_map_info	*init_map_info(void);

/* sl_map.c */
int			open_map_file(char *file_name);
void		close_map_file(int fd);

void		set_map_info(char *map_file, t_map_info *map_info);
void		set_map_size(int fd, t_map_info *map_info);
char		**make_map(int fd, t_map_info *map_info);
char		**alloc_map(t_map_info *map_info);
char		**get_read_lines(int fd, int height);

/* sl_map_check.c */
void		check_extension(char *file_name);
void		check_map_size(t_map_info *map_info);
void		check_wall(t_map_info *map_info);
void		set_other_info(t_map_info *map_info);
void		check_component(t_map_info *map_info, int *counts, int i, int j);

/* sl_path_check.c */
void		check_valid_path(t_map_info *map_info);
char		**duplicate_map(t_map_info *map_info);
void		check_next_path(char **map, int **counts, int x, int y);

/* sl_utils.c */
void		exit_on_error(t_err_types e_type, char *err_msg);
void		ft_putstr_fd(char *s, int fd);
int			sl_strcmp(const char *s1, const char *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);

/* sl_debug.c */
void	print_map(char **map, int width, int height);
void	print_map_info(t_map_info *map_info);

void	start_game(t_map_info *map_info);
void	init_game_win(void *mlx, void *mlx_win, t_map_info *map_info, void **imgs);
void	**upload_images(void *mlx);

#endif