/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 16:12:01 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_sig_char
{
	pid_t	si_pid;
	char	buf;
	int		idx;
}				t_sig_char;

t_sig_char	g_sig_char;

void	mt_translate_signal(int signo, siginfo_t *siginfo, void *context)
{
	const char	bit = 1;

	context = (void *)0;
	if (!g_sig_char.si_pid || g_sig_char.si_pid != siginfo->si_pid)
	{
		g_sig_char.si_pid = siginfo->si_pid;
		g_sig_char.idx = 0;
	}
	if (signo == SIGUSR1)
	{
		g_sig_char.buf = g_sig_char.buf | (bit << (7 - g_sig_char.idx));
		g_sig_char.idx++;
	}
	else if (signo == SIGUSR2)
	{
		g_sig_char.buf = g_sig_char.buf & ((~bit) << (7 - g_sig_char.idx));
		g_sig_char.idx++;
	}
	if (g_sig_char.idx >= 8)
	{
		write(1, &g_sig_char.buf, 1);
		g_sig_char.si_pid = 0;
		g_sig_char.idx = 0;
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
