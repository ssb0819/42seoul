/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:47 by subson            #+#    #+#             */
/*   Updated: 2024/04/24 22:25:19 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(100);
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	size_t	len;
	size_t	i;

	if (argc != 3)
		ft_putstr_fd("Error\nInsert the server PID and the string to send", 1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	i = 0;
	while (i < len)
		send_char(pid, str[i++]);
	send_char(pid, 0);
	return (0);
}
