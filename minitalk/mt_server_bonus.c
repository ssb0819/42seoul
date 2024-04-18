/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/18 00:00:32 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

t_signal_buffer	g_signal;

static void	on_signal_from_client(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	bit = 128;
	int					char_idx;
	int					bit_idx;

	context = (void *)0;
	if (!g_signal.si_pid)
		g_signal.si_pid = siginfo->si_pid;
	else if (g_signal.si_pid != siginfo->si_pid)
	{
		ft_bzero(&g_signal, sizeof(t_signal_buffer));
		g_signal.si_pid = siginfo->si_pid;
	}
	char_idx = g_signal.idx / 8;
	bit_idx = g_signal.idx % 8;
	if (signo == SIGUSR1)
		g_signal.buf[char_idx] = g_signal.buf[char_idx] | bit >> bit_idx;
	g_signal.idx++;
	if (g_signal.idx == 4)
		g_signal.byte_size = get_encoding_bytes(g_signal.buf[0]);
	if (g_signal.idx == 8 * g_signal.byte_size)
	{
		write(1, "\nget char: ", 11);
		write(1, &g_signal.buf, g_signal.byte_size);
		write(1, "\n", 1);
		send_unicode_by_sig(g_signal.si_pid, g_signal.buf, g_signal.byte_size);
		ft_bzero(&g_signal, sizeof(t_signal_buffer));
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
	sigaction(SIGUSR1, &act, (void *)0);
	sigaction(SIGUSR2, &act, (void *)0);
	while (1)
		pause();
}
