/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:34:02 by subson            #+#    #+#             */
/*   Updated: 2024/03/29 22:54:35 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			printf("%c ", map[j][i]);
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
	printf("start position : %d, %d collectible count : %d\n", map_info->start_x, map_info->start_y, map_info->colltb_count);
	print_map(map_info->map, map_info->width, map_info->height);
}
