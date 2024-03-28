/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:09:55 by subson            #+#    #+#             */
/*   Updated: 2024/03/28 23:57:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "gnl/get_next_line.h"

# define FILE_EXTENSION ".ber"

# define ERR_MSG "Error\n"
# define MAP_ERR_MSG "Error\nInvalid map file\n"

# define WALL '1'
# define BLANK '0'
# define COLLTB 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_map_info
{
	char	**map;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		colltb_count;
	int		max_path_len;
}	t_map_info;

typedef enum e_components
{
	C,
	E,
	P
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
int			get_map_height(int fd);
char		**make_map(int fd, int height);

/* sl_map_check.c */
void		check_extension(char *file_name);
void		set_map_size(t_map_info *map_info, int height);
void		check_wall(t_map_info *map_info);
void		set_other_info(t_map_info *map_info);
void		check_component(t_map_info *map_info, int *counts, int i, int j);

/* sl_utils.c */
void		exit_on_error(t_err_types e_type, char *err_msg);
void		sl_putstr_fd(char *s, int fd);
int			sl_strcmp(const char *s1, const char *s2);

/* sl_debug.c */
void	print_map(char **map, int width, int height);

#endif