/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:33:19 by subson            #+#    #+#             */
/*   Updated: 2024/03/28 22:10:40 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char **map, int width, int height)
{
	int	start_pos[2];
	int	**path_history;
	int	history_size;
	int	i;

	history_size = get_path_info(map, width, height, start_pos);
	i = 0;
	path_history = malloc(sizeof(int *) * history_size);
	if (!path_history)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	while (i < history_size)
	{
		path_history[i] = malloc(sizeof(int) * 2);
		if (!path_history[i++])
			exit_on_error(SYSTEM_ERR, ERR_MSG);
	}
	if(!check_next_path(map, start_pos, 0, 0))
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}

int	get_path_info(char **map, int width, int height, int start_pos[2])
{
	int	path_max_size;
	int	i;
	int	j;

	path_max_size = (width - 1) * (height - 1);
	i = 1;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == PLAYER)
			{
				start_pos[0] = i;
				start_pos[1] = j;
			}
			else if (map[i][j] == WALL)
				path_max_size--;
			else if (map[i][j] == COLLTB)
				colltb_count++;
			j++;
		}
		i++;
	}
	return (path_max_size);
}

int	check_next_path(char **map, int cur_pos[2], int idx, int path_found)
{
	if (path_found == 1)
		return (1);
	if (map[cur_pos[0]][cur_pos[1]])
}