/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:17:36 by subson            #+#    #+#             */
/*   Updated: 2024/04/11 19:07:13 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	**upload_tile_imgs(void *mlx)
{
	void	**images;
	int		img_w;
	int		img_h;
	int		i;

	images = malloc(sizeof(void *) * 5);
	if (!images)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	images[C] = mlx_xpm_file_to_image(mlx, COLLTB_PATH, &img_w, &img_h);
	images[E] = mlx_xpm_file_to_image(mlx, EXIT_PATH, &img_w, &img_h);
	images[P] = mlx_xpm_file_to_image(mlx, PLAYER_PATH, &img_w, &img_h);
	images[B] = mlx_xpm_file_to_image(mlx, BKGRND_PATH, &img_w, &img_h);
	images[W] = mlx_xpm_file_to_image(mlx, WALL_PATH, &img_w, &img_h);
	i = 0;
	while (i < 5)
		if (!images[i++])
			exit_on_error(SYSTEM_ERR, ERR_MSG);
	return (images);
}

void	init_window(t_param *param)
{
	int		x;
	int		y;
	char	**map;

	map = param->map_info->map;
	x = 0;
	while (x < param->map_info->width)
	{
		y = 0;
		while (y < param->map_info->height)
		{
			if (map[y][x] == WALL)
				print_tile(param, WALL, x, y);
			else
			{
				print_tile(param, BLANK, x, y);
				if (map[y][x] != BLANK)
					print_tile(param, map[y][x], x, y);
			}
			y++;
		}
		x++;
	}
	mlx_string_put(param->mlx, param->win, 20, 20, BLACK_TRGB, MV_CNT_MSG);
}

void	print_tile(t_param *param, char component, int x, int y)
{
	void	*mlx;
	void	*win;
	void	**imgs;

	mlx = param->mlx;
	win = param->win;
	imgs = param->images;
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	if (component == WALL)
		mlx_put_image_to_window(mlx, win, imgs[W], x, y);
	else if (component == BLANK)
		mlx_put_image_to_window(mlx, win, imgs[B], x, y);
	else if (component == COLLTB)
		mlx_put_image_to_window(mlx, win, imgs[C], x, y);
	else if (component == PLAYER)
		mlx_put_image_to_window(mlx, win, imgs[P], x, y);
	else if (component == EXIT)
		mlx_put_image_to_window(mlx, win, imgs[E], x, y);
}

int	exe_on_key_down(int keycode, t_param *param)
{
	int	x;
	int	y;

	x = param->map_info->player_x;
	y = param->map_info->player_y;
	if (keycode == KEY_ESC)
		exit_game(param);
	else if (keycode == ARROW_LEFT || keycode == KEY_A)
		move_character(param, x - 1, y);
	else if (keycode == ARROW_RIGHT || keycode == KEY_D)
		move_character(param, x + 1, y);
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		move_character(param, x, y + 1);
	else if (keycode == ARROW_UP || keycode == KEY_W)
		move_character(param, x, y - 1);
	return (0);
}

void	move_character(t_param *param, int next_x, int next_y)
{
	char	**map;
	int		cur_x;
	int		cur_y;

	map = param->map_info->map;
	cur_x = param->map_info->player_x;
	cur_y = param->map_info->player_y;
	if (map[next_y][next_x] == WALL)
		return ;
	if (param->map_info->colltb_count <= 0 && map[next_y][next_x] == EXIT)
		exit_game(param);
	if (map[cur_y][cur_x] == EXIT)
		print_tile(param, EXIT, cur_x, cur_y);
	else
		print_tile(param, BLANK, cur_x, cur_y);
	if (map[next_y][next_x] == COLLTB)
	{
		param->map_info->colltb_count--;
		map[next_y][next_x] = BLANK;
		print_tile(param, BLANK, next_x, next_y);
	}
	print_tile(param, PLAYER, next_x, next_y);
	param->map_info->player_x = next_x;
	param->map_info->player_y = next_y;
	print_move_count(param);
}
