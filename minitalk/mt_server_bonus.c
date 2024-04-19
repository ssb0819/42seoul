/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/19 14:30:50 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

t_signal_buffer	g_buf;

static void	write_in_buffer(void)
{
	int	i;

	i = 0;
	while (i < g_buf.byte_size)
	{
		g_buf.buffer[g_buf.buf_idx++] = g_buf.uni_c[i];
		g_buf.uni_c[i++] = 0;
	}
	g_buf.c_idx = 0;
	g_buf.bit_idx = 0;
}

static void	flush_buffer(void)
{
	//write(1, "\nflush buffer:", 14);
	write(1, &g_buf.buffer, g_buf.buf_idx);
	//write(1, "\n", 1);
	ft_bzero(&g_buf, sizeof(t_signal_buffer));
}

static void	on_signal_from_client(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	bit = 128;
	static int			reset_flag;

	context = (void *)0;
	if (!g_buf.si_pid)
		g_buf.si_pid = siginfo->si_pid;
	else if (g_buf.si_pid != siginfo->si_pid)
	{
		flush_buffer();
		g_buf.si_pid = siginfo->si_pid;
	}
	if (signo == SIGUSR1)
	{
		g_buf.uni_c[g_buf.c_idx] = g_buf.uni_c[g_buf.c_idx] | (bit >> g_buf.bit_idx);
		reset_flag = 0;
		//write(1, "1 ", 2);
	}
	else
	{
		reset_flag++;
		//write(1, "0 ", 2);
	}
	g_buf.c_idx += (++(g_buf.bit_idx) / 8);
	g_buf.bit_idx %= 8;
	if (reset_flag == 8 || (g_buf.c_idx == 4 && g_buf.bit_idx > 0))
	{
		flush_buffer();
		reset_flag = 0;
	}
	else if (g_buf.c_idx == 0 && g_buf.bit_idx == 4)
		g_buf.byte_size = get_encoding_bytes(g_buf.uni_c[0]);
	else if (g_buf.byte_size && g_buf.c_idx == g_buf.byte_size)
	{
		//write(1, "\nget chat:", 10);
		//write(1, &g_buf.uni_c, g_buf.byte_size);
		//write(1, "\n", 1);
		send_str_by_sig(g_buf.si_pid, g_buf.uni_c, g_buf.byte_size);
		write_in_buffer();
	}
}

int	main(void)
{
	struct sigaction	act;

	print_my_pid();
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = on_signal_from_client;
	sigaction(SIGUSR1, &act, (void *)0); // 예외처리?
	sigaction(SIGUSR2, &act, (void *)0);
	while (1)
		pause();
}
