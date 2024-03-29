/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:33:19 by subson            #+#    #+#             */
/*   Updated: 2024/03/29 21:15:52 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_path(t_map_info *map_info)
{
	int	path_len;
	int	**path;
	int	*start_position;
	int	i;

	path_len = map_info->max_path_len;
	path = malloc(sizeof(int *) * path_len);
	if (!path)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	i = 0;
	while (i < path_len)
	{
		path[i] = malloc(sizeof(int) * 2);
		if (!path[i++])
			exit_on_error(SYSTEM_ERR, ERR_MSG);
	}
	path[0][0] = map_info->start_x;
	path[0][1] = map_info->start_y;
	if (!check_next_path(map_info, path, 0, 0))
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}


int	check_next_path(t_map_info *map_info, int **path, int idx, int colltb_num)
{
	int	cur_x;
	int	cur_y;
	int	i;

	cur_x = path[idx][0];
	cur_y = path[idx][1];
	if (map_info->map[cur_x][cur_y] == EXIT && colltb_num == map_info->colltb_count)
		return (1);
	if (map_info->map[cur_x][cur_y] == WALL)
		return (0);
	if (map_info->map[cur_x][cur_y] == PLAYER)
		return (0);
	i = 0;
	while (++i < idx)
	{
		if (path[i][0] == cur_x && path[i][1] == cur_y)
			return (0);
	}
	
}
