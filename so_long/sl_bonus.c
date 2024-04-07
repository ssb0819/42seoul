/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:06:07 by subson            #+#    #+#             */
/*   Updated: 2024/04/07 21:39:34 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move_count(t_param *param)
{
	void	*mlx;
	void	*win;
	void	*wall;

	mlx = param->mlx;
	win = param->win;
	wall = param->images[W];
	param->move_count++;
	mlx_put_image_to_window(mlx, win, wall, 3 * TILE_SIZE, 0);
	if (param->move_count >= 100000)
		mlx_put_image_to_window(mlx, win, wall, 4 * TILE_SIZE, 0);
	mlx_string_put(mlx, win, 205, 20, BLUE_TRGB, ft_itoa(param->move_count));
}
