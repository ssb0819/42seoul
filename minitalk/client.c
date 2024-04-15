/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:47 by subson            #+#    #+#             */
/*   Updated: 2024/04/15 22:19:29 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_signal(int pid, char c, int cnt)
{
	if (cnt < 7)
		send_signal(pid, c >> 1, ++cnt);
	if (c % 2 == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(10);
}

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
	while (i < len)
		send_signal(pid, str[i++], 0);
}
