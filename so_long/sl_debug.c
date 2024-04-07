/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:34:02 by subson            #+#    #+#             */
/*   Updated: 2024/04/07 20:20:37 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_lst(void *content)
{
	char	*str;

	str = content;
	ft_putstr_fd(str, 1);
}

void	print_read_lines(t_list *lines)
{
	ft_lstiter(lines, print_lst);
}

void	print_map(char **map, int width, int height)
{
	int	i;
	int	j;

	printf("printing map.....\n");
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_map_info(t_map_info *map_info)
{
	printf("printing map info ......\n");
	printf("width: %d height: %d\n", map_info->width, map_info->height);
	printf("start position : %d, %d collectible count : %d\n", \
			map_info->player_x, map_info->player_y, map_info->colltb_count);
	print_map(map_info->map, map_info->width, map_info->height);
}
