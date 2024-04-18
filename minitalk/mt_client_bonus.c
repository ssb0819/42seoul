/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:47 by subson            #+#    #+#             */
/*   Updated: 2024/04/18 20:03:47 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

#include <stdio.h>

t_signal_buffer	g_signal;

static void	send_reset_signal(pid_t pid)
{
	const unsigned char	c = 0;

	usleep(1000);
	send_char_by_signal(pid, c, 0);
	usleep(1000);
}

static void	on_signal_from_server(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	bit = 128;
	int					char_idx;
	int					bit_idx;

	context = (void *)0;
	if (!g_signal.si_pid)
		g_signal.si_pid = siginfo->si_pid;
	if (g_signal.si_pid != siginfo->si_pid)
	{
		ft_bzero(&g_signal, sizeof(t_signal_buffer));
		g_signal.si_pid = siginfo->si_pid;
	}
	char_idx = g_signal.idx / 8;
	bit_idx = g_signal.idx % 8;
	if (signo == SIGUSR1)
	{
		g_signal.buf[char_idx] = g_signal.buf[char_idx] | bit >> bit_idx;
		g_signal.idx++;
	}
	else
	{
		g_signal.idx++;
	}
}

static int	send_str_to_server(pid_t pid, char *s)
{
	unsigned char	*str;
	int				try_cnt;
	int				wait_cnt;
	char			*buf_p;

	str = (unsigned char *)s;
	buf_p = (char *)g_signal.buf;
	try_cnt = 0;
	while (*str)
	{
		ft_bzero(&g_signal, sizeof(t_signal_buffer));
		g_signal.byte_size = get_encoding_bytes(*str);
		send_unicode_by_sig(pid, str, g_signal.byte_size);
		wait_cnt = 0;
		while (g_signal.idx != 8 * g_signal.byte_size && wait_cnt++ < 10 * g_signal.byte_size)
			usleep(500);
		if (ft_strncmp((char *)g_signal.buf, (char *)str, \
						(size_t)g_signal.byte_size) == 0)
		{
			str += g_signal.byte_size;
			try_cnt = 0;
		}
		else
			send_reset_signal(pid);
		if (++try_cnt == 3)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;

	if (argc != 3)
		ft_putstr_fd("Error\nInsert the server PID and the string to send", 1);
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = on_signal_from_server;
	sigaction(SIGUSR1, &act, (void *)0);
	sigaction(SIGUSR2, &act, (void *)0);
	pid = ft_atoi(argv[1]);
	if (send_str_to_server(pid, argv[2]))
		write(1, "Transfer succeeded.\n", 20);
	else
		write(1, "Transfer failed.\n", 17);
}
