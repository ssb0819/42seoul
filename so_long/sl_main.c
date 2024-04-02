/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:06:45 by subson            #+#    #+#             */
/*   Updated: 2024/04/02 22:05:41 by subson           ###   ########.fr       */
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
		printf("%s", line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_map_info	*map_info;

	if (argc != 2)
		exit_on_error(RUNTIME_ERR, MAP_ERR_MSG);
	map_info = init_map_info();
	set_map_info(argv[1], map_info);
	// print_map_info(map_info);
	check_valid_path(map_info);
	start_game(map_info);
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
	return (map_info);
}
