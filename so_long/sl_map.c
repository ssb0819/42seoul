/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:28 by subson            #+#    #+#             */
/*   Updated: 2024/03/26 18:32:43 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_map(char *file_name)
{
	char	**map;
	int		w;
	int		h;

	if (!get_map_size(file_name, &w, &h))
		return (0);
	map = get_map(file_name, h);
	if (!map)
		return (0);
	if (is_composed_properly(map, w, h) && has_valid_path(map, w, h))
		return (1);
	while (h > 0)
		free(map[h--]);
	free(map);
	return (0);
}

int	get_map_size(char *file_name, int *width, int *height)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	*width = 0;
	*height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (height == 0)
			*width = sl_strlen(line);
		else if (*width != sl_strlen(line))
		{
			free(line);
			return (0);
		}
		(*height)++;
		free(line);
	}
	if (height == 0)
		return (0);
	return (1);
}

char	**get_map(char *file_name, int height)
{
	int		i;
	int		fd;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ((void **)0);
	map = malloc(sizeof(char *) * height);
	if (!map)
		return ((void **)0);
	i = 0;
	while (i < height)
		map[i++] = get_next_line(fd);
}

/* counts : [ collectible_count, exit_count, player_count ] */
int	is_composed_properly(char **map, int width, int height)
{
	int		counts[3];
	int		i;
	int		j;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				if (map[i][j] != '1')
					return (0);
			if (map[i][j] == 'C')
				counts[0]++;
			else if (map[i][j] == 'E')
				counts[1]++;
			else if (map[i][j] == 'P')
				counts[2]++;
			j++;
		}
		if (counts[1] > 1 || counts[2] > 1)
			return (0);
		i++;
	}
	if (counts[0] == 0 || counts[1] == 0 || counts[2] == 0)
		return (0);
	return (1);
}

int	check_component(char **map, int *c_count, int *e_count, int *p_count)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				if (map[i][j] != '1')
					return (0);
			if (map[i][j] == 'C')
				counts[0]++;
			else if (map[i][j] == 'E')
				counts[1]++;
			else if (map[i][j] == 'P')
				counts[2]++;
			j++;
		}
		if (counts[1] > 1 || counts[2] > 1)
			return (0);
		i++;
	}
}
