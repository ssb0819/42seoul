/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:22:02 by subson            #+#    #+#             */
/*   Updated: 2024/04/25 17:36:02 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

extern t_signal_buffer g_buf;

void	sig_to_unicode(int signo, siginfo_t *siginfo, void *context)
{
	context = (void *)0;
	if (g_buf.si_pid && g_buf.si_pid != siginfo->si_pid)
	{
		flush_buffer();
		init_unicode();
	}
	g_buf.si_pid = siginfo->si_pid;
	if (signo == SIGUSR1)
	{
		add_bit_to_unicode(1);
		g_buf.flag = (g_buf.flag << 1) | 1;
	}
	else
	{
		add_bit_to_unicode(0);
		g_buf.flag = g_buf.flag << 1;
	}
	g_buf.sig_cnt++;
}

void	init_unicode(void)
{
	g_buf.sig_cnt = 0;
	g_buf.byte_size = 0;
}

void	add_bit_to_unicode(int bit)
{
	const unsigned char	one_bit = 1;
	int					c_idx;
	int					bit_idx;

	if (g_buf.sig_cnt >= 32)
		return ;
	c_idx = g_buf.sig_cnt / 8;
	bit_idx = g_buf.sig_cnt % 8;
	if (bit)
	{
		g_buf.unicode[c_idx] = \
		g_buf.unicode[c_idx] | (one_bit << (7 - bit_idx));
	}
	else
	{
		g_buf.unicode[c_idx] = \
		g_buf.unicode[c_idx] & (~one_bit << (7 - bit_idx));
	}
}

void	put_unicode(void)
{
	int	i;

	i = 0;
	if ((g_buf.byte_size + g_buf.buf_idx) >= 1020)
		flush_buffer();
	while (i < g_buf.byte_size)
	{
		g_buf.buffer[g_buf.buf_idx + i] = g_buf.unicode[i];
		i++;
	}
}

void	flush_buffer(void)
{
	if (!g_buf.buf_idx)
		return ;
	write(1, &g_buf.buffer, g_buf.buf_idx);
	g_buf.buf_idx = 0;
}
