/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:31:29 by subson            #+#    #+#             */
/*   Updated: 2024/04/04 22:20:59 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_execute(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		exit_game(param);
	else if (keycode == ARROW_LEFT || keycode == KEY_A)
		move_character(param, -1, 0);
	else if (keycode == ARROW_RIGHT || keycode == KEY_D)
		move_character(param, +1, 0);
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		move_character(param, 0, -1);
	else if (keycode == ARROW_UP || keycode == KEY_W)
		move_character(param, 0, +1);
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
	next_x += cur_x;
	next_y += cur_y;

	if (map[next_x][next_y] == WALL)
		return ;
	ft_putstr_fd(ft_itoa(++(param->move_count)), 1);
	if (map[next_x][next_y] == EXIT && param->map_info->colltb_count <= 0)
		exit_game(param);
	print_image(param, BLANK, cur_x, cur_y);
	if (map[next_x][next_y] == COLLTB)
	{
		param->map_info->colltb_count--;
		map[next_x][next_y] = BLANK;
		print_image(param, BLANK, cur_x, cur_y);
	}
	print_image(param, PLAYER, next_x, next_y);
	param->map_info->player_x = next_x;
	param->map_info->player_x = next_y;
}
