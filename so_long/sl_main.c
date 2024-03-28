/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:06:45 by subson            #+#    #+#             */
/*   Updated: 2024/03/28 23:58:37 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 


void	test_gnl(char *file_name)
{
	int		fd;
	char	*line;
	ssize_t	l;

	fd = open(file_name, O_RDONLY);
	while (1)
	{
		l = get_next_line(fd, &line);
		printf("%zd\n", l);
		if (l <= 0)
			return ;
		sl_putstr_fd(line, 1);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_map_info	*map_info;

	if (argc != 2)
	{
		sl_putstr_fd(MAP_ERR_MSG, 2);
		exit(1);
	}
	map_info = init_map_info();
	set_map_info(argv[1], map_info);
	// check_path(map_info);
	// free_map_info(map_info);
}

t_map_info	*init_map_info(void)
{
	t_map_info	*map_info;

	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	map_info->map = (char **)0;
	map_info->width = 0;
	map_info->height = 0;
	map_info->start_x = 0;
	map_info->start_y = 0;
	map_info->colltb_count = 0;
	map_info->max_path_len = 0;
	return (map_info);
}
