/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:47 by subson            #+#    #+#             */
/*   Updated: 2024/04/18 22:05:28 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

t_signal_buffer	g_buf;

static void	send_reset_signal(pid_t pid)
{
	const unsigned char	c = 0;

	write(1, "retry sending signal\n", 21); /* 디버깅 */
	usleep(100);
	send_char_by_signal(pid, c, 0);
	usleep(100);
}

static void	on_signal_from_server(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	bit = 128;

	context = (void *)0;
	if (signo == SIGUSR1 || siginfo->si_signo == SIGUSR1)
		g_buf.uni_c[g_buf.c_idx] = g_buf.uni_c[g_buf.c_idx] | bit >> g_buf.bit_idx;
	g_buf.c_idx += ++(g_buf.bit_idx) / 8;
	g_buf.bit_idx %= 8;
}

static int	send_str_to_server(pid_t pid, char *s)
{
	unsigned char	*str;
	int				try_cnt;
	int				wait_cnt;

	str = (unsigned char *)s;
	try_cnt = 0;
	while (*str)
	{
		ft_bzero(&g_buf, sizeof(t_signal_buffer));
		g_buf.byte_size = get_encoding_bytes(*str);
		send_str_by_sig(pid, str, g_buf.byte_size);
		wait_cnt = 0;
		while (g_buf.c_idx != g_buf.byte_size && wait_cnt++ < 10 * g_buf.byte_size)
			usleep(200);
		if (ft_strncmp((char *)g_buf.uni_c, (char *)str, \
						(size_t)g_buf.byte_size) == 0)
		{
			//write(1, "\nget chat:", 10);
			//write(1, &g_buf.uni_c, g_buf.byte_size);
			str += g_buf.byte_size;
			try_cnt = 0;
		}
		else
			send_reset_signal(pid);
		if (++try_cnt == 3)
			return (0);
	}
	send_reset_signal(pid);
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
