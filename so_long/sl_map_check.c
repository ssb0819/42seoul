/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:28 by subson            #+#    #+#             */
/*   Updated: 2024/03/28 23:58:52 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *file_name)
{
	int	len;
	int	ext_len;

	len = ft_strlen(file_name);
	ext_len = ft_strlen(FILE_EXTENSION);
	file_name += (len - ext_len);
	if (sl_strcmp(file_name, FILE_EXTENSION) != 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}

void	set_map_size(t_map_info *map_info, int height)
{
	int		i;
	int		width;
	char	**map;

	map = map_info->map;
	i = 0;
	while (i < height)
	{
		if (i == 0)
			width = ft_strlen(map[i]) - 1;
		else if (i < height - 1 && width + 1 != (int)ft_strlen(map[i]))
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		else if (i == height - 1 && width != (int)ft_strlen(map[i]))
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		i++;
	}
	if (width < 3 || height < 3 || width + height < 8)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	map_info->width = width;
	map_info->height = height;
	// map이 너무 큰 경우 예외처리 추가 예정
}

void	check_wall(t_map_info *map_info)
{
	int		i;
	char	**map;

	map = map_info->map;
	i = 0;
	while (i < map_info->width)
	{
		if (map[0][i] != WALL || map[map_info->height - 1][i] != WALL)
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		i++;
	}
	i = 0;
	while (i < map_info->height)
	{
		if (map[i][0] != WALL || map[i][map_info->width - 1] != WALL)
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		i++;
	}
}

void	set_other_info(t_map_info *map_info)
{
	int		counts[4];
	int		i;
	int		j;

	counts[C] = 0;
	counts[E] = 0;
	counts[P] = 0;
	map_info->max_path_len = (map_info->width - 1) * (map_info->height - 1);
	i = 1;
	while (i < map_info->height - 1)
	{
		j = 1;
		while (j < map_info->width - 1)
		{
			check_component(map_info, counts, i, j);
			j++;
		}
		i++;
	}
	if (counts[C] == 0 || counts[E] == 0 || counts[P] == 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	map_info->colltb_count = counts[C];
}

void	check_component(t_map_info *map_info, int *counts, int i, int j)
{
	char	component;

	component = map_info->map[i][j];
	if (component == PLAYER)
	{
		counts[P]++;
		map_info->start_x = i;
		map_info->start_y = j;
	}
	else if (component == COLLTB)
		counts[C]++;
	else if (component == EXIT)
		counts[E]++;
	else if (component == WALL)
		map_info->max_path_len--;
	else if (component != BLANK)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	if (counts[E] > 1 || counts[P] > 1)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
}
