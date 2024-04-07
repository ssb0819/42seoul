/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:28 by subson            #+#    #+#             */
/*   Updated: 2024/04/07 20:13:47 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *file_name)
{
	int	len;
	int	ext_len;

	len = ft_strlen(file_name);
	ext_len = ft_strlen(MAP_EXTENSION);
	file_name += (len - ext_len);
	if (sl_strcmp(file_name, MAP_EXTENSION) != 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}

void	check_wall(t_map_info *map_info)
{
	int		i;
	int		horizontal_last;
	int		vertical_last;
	char	**map;

	i = 0;
	horizontal_last = map_info->width - 1;
	vertical_last = map_info->height - 1;
	map = map_info->map;
	while (i <= horizontal_last)
	{
		if (map[0][i] != WALL || map[vertical_last][i] != WALL)
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		i++;
	}
	i = 0;
	while (i <= vertical_last)
	{
		if (map[i][0] != WALL || map[i][horizontal_last] != WALL)
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		i++;
	}
}

void	check_next_path(char **map, int *counts, int x, int y)
{
	if (counts[C] == 0 && counts[E] == 0)
		return ;
	if (map[y][x] == WALL || map[y][x] == VISITED)
		return ;
	if (map[y][x] == COLLTB)
		counts[C]--;
	else if (map[y][x] == EXIT)
		counts[E]--;
	map[y][x] = VISITED;
	check_next_path(map, counts, x + 1, y);
	check_next_path(map, counts, x - 1, y);
	check_next_path(map, counts, x, y + 1);
	check_next_path(map, counts, x, y - 1);
}

void	check_component(t_map_info *map_info, int *counts, int x, int y)
{
	char	component;

	component = map_info->map[y][x];
	if (component == PLAYER)
	{
		counts[P]++;
		map_info->player_x = x;
		map_info->player_y = y;
	}
	else if (component == COLLTB)
		counts[C]++;
	else if (component == EXIT)
		counts[E]++;
	else if ((component != WALL && component != BLANK) \
			|| counts[E] > 1 || counts[P] > 1)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}
