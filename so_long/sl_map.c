/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:24:50 by subson            #+#    #+#             */
/*   Updated: 2024/03/28 23:54:12 by subson           ###   ########.fr       */
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
	int			height;

	check_extension(map_file);
	height = get_map_height(open_map_file(map_file));
	map_info->map = make_map(open_map_file(map_file), height);
	set_map_size(map_info, height);
	check_wall(map_info);
	set_other_info(map_info);
}

int	get_map_height(int fd)
{
	char	*line;
	ssize_t	line_len;
	int		height;

	height = 0;
	while (1)
	{
		line_len = get_next_line(fd, &line);
		if (line_len <= 0)
			break ;
		height++;
		free(line);
	}
	close_map_file(fd);
	if (line_len == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	if (height == 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	return (height);
}

char	**make_map(int fd, int height)
{
	char	**map;
	char	*line;
	int		i;
	ssize_t	line_len;

	map = malloc(sizeof(char *) * height);
	if (!map)
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
		map[i++] = line;
	}
	close_map_file(fd);
	if (line_len == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	return (map);
}
