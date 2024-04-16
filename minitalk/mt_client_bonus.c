/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:47 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 18:11:00 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	size_t	len;
	size_t	i;

	if (argc != 3)
	{
		ft_putstr_fd("Error\nInsert the server PID and the string to send", 1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	i = 0;
	printf("%zu\n", len);
	while (i < len)
	{
		send_signal(pid, str[i], 0);
		i++;
	}
}
