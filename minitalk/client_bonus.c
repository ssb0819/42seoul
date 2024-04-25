/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:47 by subson            #+#    #+#             */
/*   Updated: 2024/04/25 19:26:18 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

t_signal_buffer	g_buf;

static void	send_sign(pid_t pid, unsigned short sign)
{
	unsigned char	*p;

	if (sign != END_SIGN || sign != ERR_SIGN)
		return ;
	p = (unsigned char *)&sign;
	send_str(pid, p, 2);
}

static void	send_str_to_server(pid_t pid, char *s)
{
	unsigned char	*str;
	int				try_cnt;
	int				wait_cnt;

	str = (unsigned char *)s;
	try_cnt = 0;
	while (*str && try_cnt++ < 5)
	{
		init_unicode();
		g_buf.byte_size = get_encoding_bytes_len(*str);
		send_str(pid, str, g_buf.byte_size);
		wait_cnt = 0;
		while (g_buf.sig_cnt < 8 * g_buf.byte_size && wait_cnt < 10)
			if (usleep(200) == 0)
				wait_cnt++;
		if (g_buf.sig_cnt == 8 * g_buf.byte_size && \
		ft_strncmp((char *)g_buf.unicode, (char *)str, g_buf.byte_size) == 0)
		{
			str += g_buf.byte_size;
			try_cnt = 0;
		}
		else
			send_sign(pid, ERR_SIGN);
	}
	send_sign(pid, END_SIGN);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putstr_fd("Error\nInsert the server PID and the string to send\n", 1);
		exit(1);
	}
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_to_unicode;
	sigaction(SIGUSR1, &act, (void *)0);
	sigaction(SIGUSR2, &act, (void *)0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_putstr_fd("Error\nInsert valid server PID\n", 1);
	else if (ft_strlen(argv[2]) > 0)
		send_str_to_server(pid, argv[2]);
}
