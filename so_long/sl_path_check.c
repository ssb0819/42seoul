/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:33:19 by subson            #+#    #+#             */
/*   Updated: 2024/04/04 22:24:34 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_path(t_map_info *map_info)
{
	char	**dup_map;
	int		*counts;
	int		i;

	dup_map = duplicate_map(map_info);
	counts = malloc(sizeof(int) * 2);
	if (!counts)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	counts[C] = map_info->colltb_count;
	counts[E] = 1;
	check_next_path(dup_map, &counts, map_info->player_x, map_info->player_y);
	i = 0;
	while (i < map_info->width)
		free(dup_map[i++]);
	free(counts);
	if (counts[C] != 0 || counts[E] != 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}

char	**duplicate_map(t_map_info *map_info)
{
	char	**map;
	int		i;

	map = alloc_map(map_info);
	if (!map)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	i = 0;
	while (i < map_info->width)
	{
		map[i] = ft_memcpy(map[i], map_info->map[i], map_info->height + 1);
		i++;
	}
	return (map);
}

void	check_next_path(char **map, int **counts, int x, int y)
{
	if ((*counts)[C] == 0 && (*counts)[E] == 0)
		return ;
	if (map[x][y] == WALL || map[x][y] == VISITED)
		return ;
	if (map[x][y] == COLLTB)
		(*counts)[C]--;
	else if (map[x][y] == EXIT)
		(*counts)[E]--;
	map[x][y] = VISITED;
	check_next_path(map, counts, x + 1, y);
	check_next_path(map, counts, x - 1, y);
	check_next_path(map, counts, x, y + 1);
	check_next_path(map, counts, x, y - 1);
}
