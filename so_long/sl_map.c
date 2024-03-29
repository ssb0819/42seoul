/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:24:50 by subson            #+#    #+#             */
/*   Updated: 2024/03/29 23:05:26 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_on_error(SYSTEM_ERR, MAP_ERR_MSG);
	return (fd);
}

void	close_map_file(int fd)
{
	if (close(fd) == -1)
		exit_on_error(SYSTEM_ERR, MAP_ERR_MSG);
}

void	set_map_info(char *map_file, t_map_info *map_info)
{
	check_extension(map_file);
	set_map_size(open_map_file(map_file), map_info);
	check_map_size(map_info);
	map_info->map = make_map(open_map_file(map_file), map_info);
	check_wall(map_info);
	set_other_info(map_info);
}

void	set_map_size(int fd, t_map_info *map_info)
{
	char	*line;
	ssize_t	line_len;
	int		read_last;

	read_last = 0;
	line_len = get_next_line(fd, &line);
	map_info->width = line_len - 1;
	while (line_len > 0)
	{
		if (read_last)
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		else if (line_len == map_info->width)
			read_last = 1;
		else if (line_len - 1 != map_info->width)
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);

		free(line);
		line_len = get_next_line(fd, &line);
		map_info->height++;
	}
	close_map_file(fd);
	if (!read_last)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	if (line_len == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
}

char	**make_map(int fd, t_map_info *map_info)
{
	char	**map;
	char	**lines;
	int		i;
	int		j;

	map = alloc_map(map_info);
	if (!map)
	{
		close_map_file(fd);
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	}
	lines = get_read_lines(fd, map_info->height);
	i = 0;
	while (i < map_info->width)
	{
		j = 0;
		while (j < map_info->height)
		{
			map[i][j] = lines[j][i];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	close_map_file(fd);
	i = 0;
	while (i < map_info->height)
		free(lines[i++]);
	free(lines);
	return (map);
}

char	**alloc_map(t_map_info *map_info)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * map_info->width);
	if (!map)
		return ((void *)0);
	i = 0;
	while (i < map_info->width)
	{
		map[i] = malloc(sizeof(char) * (map_info->height + 1));
		if (!map[i++])
			return ((void *)0);
	}
	return (map);
}

char	**get_read_lines(int fd, int height)
{
	int		i;
	char	*line;
	ssize_t	line_len;
	char	**lines;

	lines = malloc(sizeof(char *) * height);
	if (!lines)
	{
		close_map_file(fd);
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	}
	i = 0;
	while (i < height)
	{
		line_len = get_next_line(fd, &line);
		if (line_len <= 0)
			break ;
		lines[i++] = line;
	}
	if (line_len == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	return (lines);
}
