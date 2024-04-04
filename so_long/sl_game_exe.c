/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:17:36 by subson            #+#    #+#             */
/*   Updated: 2024/04/04 22:20:00 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	start_game(t_map_info *map_info)
{
	t_param		param;

	param.map_info = map_info;
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, map_info->width * 64, map_info->height * 64, "so_long");
	param.images = upload_images(param.mlx);
	param.move_count = 0;
	init_window(&param);
	mlx_hook(param.win, ON_DESTROY, 0, exit_game, &param);
	mlx_hook(param.win, ON_KEYDOWN, 0, key_execute, &param);
	mlx_loop(param.mlx);
}

void	**upload_images(void *mlx)
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
	int		i;
	int		j;
	char	**map;

	map = param->map_info->map;
	i = 0;
	while (i < param->map_info->width)
	{
		j = 0;
		while (j < param->map_info->height)
		{
			if (map[i][j] == WALL)
				print_image(param, WALL, i, j);
			else
			{
				print_image(param, BLANK, i, j);
				if (map[i][j] != BLANK)
					print_image(param, map[i][j], i, j);
			}
			j++;
		}
		i++;
	}
}

int	exit_game(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

void	print_image(t_param *param, char component, int x, int y)
{
	void	*mlx;
	void	*win;
	void	**imgs;

	mlx = param->mlx;
	win = param->win;
	imgs = param->images;
	x *= 64;
	y *= 64;
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
