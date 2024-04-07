/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:24:50 by subson            #+#    #+#             */
/*   Updated: 2024/04/07 19:53:29 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*read_map_file(int fd, t_map_info *map_info)
{
	char	*line;
	ssize_t	line_len;
	t_list	*read_lines;

	read_lines = (void *)0;
	while (1)
	{
		line_len = get_next_line(fd, &line);
		if (line_len <= 0)
			break ;
		if (!ft_lstadd_back(&read_lines, ft_lstnew(line)))
		{
			close(fd);
			exit_on_error(SYSTEM_ERR, ERR_MSG);
		}
		map_info->height++;
	}
	if (close(fd) == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	if (line_len == -1)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	return (read_lines);
}

void	set_map_size(t_list *read_lines, t_map_info *map_info)
{
	int		i;
	int		height;
	size_t	width;

	height = map_info->height;
	width = ft_strlen(read_lines->content) - 1;
	if (width < 3 || height < 3 || width + (size_t)height < 8 \
	|| width * TILE_SIZE > SCREEN_WIDTH || height * TILE_SIZE > SCREEN_HEIGHT)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	i = 1;
	while (i < height)
	{
		read_lines = read_lines->next;
		if ((i < height - 1 && width != ft_strlen(read_lines->content) - 1) \
			|| (i == height - 1 && width != ft_strlen(read_lines->content)))
			exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
		i++;
	}
	map_info->width = (int)width;
}

void	set_map(t_list *read_lines, t_map_info *map_info)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * map_info->height);
	if (!map)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	i = 0;
	while (read_lines)
	{
		map[i++] = read_lines->content;
		read_lines = read_lines->next;
	}
	map_info->map = map;
}

void	set_other_info(t_map_info *map_info)
{
	int		counts[4];
	int		x;
	int		y;

	counts[C] = 0;
	counts[E] = 0;
	counts[P] = 0;
	x = 1;
	while (x < map_info->width - 1)
	{
		y = 1;
		while (y < map_info->height - 1)
		{
			check_component(map_info, counts, x, y);
			y++;
		}
		x++;
	}
	if (counts[C] == 0 || counts[E] == 0 || counts[P] == 0)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	map_info->colltb_count = counts[C];
}

char	**duplicate_map(t_map_info *map_info)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * map_info->height);
	if (!map)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	i = 0;
	while (i < map_info->height)
	{
		map[i] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map[i])
			exit_on_error(SYSTEM_ERR, ERR_MSG);
		ft_memcpy(map[i], map_info->map[i], map_info->width + 1);
		map[i][map_info->width] = '\0';
		i++;
	}
	return (map);
}
