/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:17:36 by subson            #+#    #+#             */
/*   Updated: 2024/04/02 23:50:23 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	start_game(t_map_info *map_info)
{
	void	*mlx;
	void	*mlx_win;
	void	**images;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_info->width * 64, map_info->height * 64, "so_long");
	images = upload_images(mlx);
	init_game_win(mlx, mlx_win, map_info, images);
	mlx_loop(mlx);
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

void	init_game_win(void *mlx, void *win, t_map_info *map_info, void **imgs)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_info->width)
	{
		j = 0;
		while (j < map_info->height)
		{
			if (map_info->map[i][j] == WALL)
				mlx_put_image_to_window(mlx, win, imgs[W], i * 64, j * 64);
			else
			{
				mlx_put_image_to_window(mlx, win, imgs[B], i * 64, j * 64);
				if (map_info->map[i][j] == PLAYER)
					mlx_put_image_to_window(mlx, win, imgs[P], i * 64, j * 64);
				else if (map_info->map[i][j] == COLLTB)
					mlx_put_image_to_window(mlx, win, imgs[C], i * 64, j * 64);
				else if (map_info->map[i][j] == EXIT)
					mlx_put_image_to_window(mlx, win, imgs[E], i * 64, j * 64);
			}
			j++;
		}
		i++;
	}
}
