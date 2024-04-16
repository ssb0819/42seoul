/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:06:45 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 21:40:22 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_map_info(char *map_file, t_map_info *map_info)
{
	int		fd;
	t_list	*read_lines;

	check_extension(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_on_error(SYSTEM_ERR, MAP_ERR_MSG);
	read_lines = read_map_file(fd, map_info);
	if (close(fd) == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	set_map_size(read_lines, map_info);
	set_map(read_lines, map_info);
	ft_lstclear(&read_lines, (void *)0);
	check_wall(map_info);
	set_other_info(map_info);
}

static void	check_valid_path(t_map_info *map_info)
{
	char	**dup_map;
	int		counts[2];
	int		*counts_p;
	int		i;

	dup_map = map_info->map;
	map_info->map = duplicate_map(map_info);
	counts[C] = map_info->colltb_count;
	counts[E] = 1;
	counts_p = counts;
	check_next_path(dup_map, counts, map_info->player_x, map_info->player_y);
	i = 0;
	while (i < map_info->height)
		free(dup_map[i++]);
	free(dup_map);
	if (counts[C] != 0 || counts[E] != 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}

static void	game_exe(t_map_info *map_info)
{
	t_param		param;

	param.map_info = map_info;
	param.mlx = mlx_init();
	if (!param.mlx)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	param.win = mlx_new_window(param.mlx, map_info->width * TILE_SIZE, \
							map_info->height * TILE_SIZE, "so_long");
	if (!param.win)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	param.images = upload_tile_imgs(param.mlx);
	param.move_count = 0;
	init_window(&param);
	mlx_hook(param.win, ON_DESTROY, 0, exit_game, &param);
	mlx_hook(param.win, ON_KEYDOWN, 0, exe_on_key_down, &param);
	mlx_loop(param.mlx);
}

int	main(int argc, char **argv)
{
	t_map_info	*map_info;

	if (argc != 2)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	ft_bzero(map_info, sizeof(t_map_info));
	set_map_info(argv[1], map_info);
	check_valid_path(map_info);
	game_exe(map_info);
}
