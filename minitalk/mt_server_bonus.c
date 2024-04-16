/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 18:11:40 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

t_signal_buffer	g_signal;

void	init_signal_buffer(void)
{
	g_signal.si_pid = 0;
	g_signal.byte_cnt = 0;
	g_signal.idx = 0;
	g_signal.buf[0] = 0;
	g_signal.buf[1] = 0;
	g_signal.buf[2] = 0;
	g_signal.buf[3] = 0;
}

void	set_byte_cnt(void)
{
	if (g_signal.buf[0] < TWO_BYTE)
		g_signal.byte_cnt = 1;
	else if (g_signal.buf[0] < THREE_BYTE)
		g_signal.byte_cnt = 2;
	else if (g_signal.buf[0] < FOUR_BYTE)
		g_signal.byte_cnt = 3;
	else
		g_signal.byte_cnt = 4;
}

void	mt_translate_signal(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	bit = 128;
	int					char_idx;
	int					bit_idx;

	context = (void *)0;
	if (g_signal.si_pid != siginfo->si_pid)
	{
		init_signal_buffer();
		g_signal.si_pid = siginfo->si_pid;
	}
	char_idx = g_signal.idx / 8;
	bit_idx = g_signal.idx % 8;
	if (signo == SIGUSR1)
	{
		g_signal.buf[char_idx] = g_signal.buf[char_idx] | bit >> bit_idx;
	}
	g_signal.idx++;
	if (g_signal.idx == 4)
		set_byte_cnt();
	if (g_signal.idx == 8 * g_signal.byte_cnt)
	{
		write(1, &g_signal.buf, g_signal.byte_cnt);
		init_signal_buffer();
	}
}

int	main(void)
{
	struct sigaction	act;
	char				*pid_str;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = mt_translate_signal;
	pid_str = ft_itoa(getpid());
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &act, (void *)0);
	sigaction(SIGUSR2, &act, (void *)0);
	while (1)
		pause();
}
