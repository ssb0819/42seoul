/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/25 17:36:25 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

t_signal_buffer	g_buf;

static void	to_char_and_respond(int signo, siginfo_t *siginfo, void *context)
{
	sig_to_unicode(signo, siginfo, context);
	if (g_buf.sig_cnt == 4)
		g_buf.byte_size = get_encoding_bytes_len(g_buf.unicode[0]);
	else if (g_buf.sig_cnt >= 16)
	{
		if (g_buf.flag == ERR_SIGN)
			init_unicode();
		else if (g_buf.flag == END_SIGN)
		{
			flush_buffer();
			init_unicode();
			g_buf.si_pid = 0;
		}
	}
	if (g_buf.byte_size && g_buf.sig_cnt == 8 * g_buf.byte_size)
	{
		send_str(g_buf.si_pid, g_buf.unicode, g_buf.byte_size);
		put_unicode();
		g_buf.buf_idx += g_buf.byte_size;
		init_unicode();
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
	act.sa_sigaction = to_char_and_respond;
	if (sigaction(SIGUSR1, &act, (void *)0) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &act, (void *)0) == -1)
		exit(1);
	while (1)
	{
		if (usleep(100000) == 0)
			flush_buffer();
	}
}
