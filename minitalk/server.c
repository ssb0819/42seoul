/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/12 14:46:28 by subson           ###   ########.fr       */
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

void	mt_sigaction(int signo, siginfo_t *siginfo, void *context)
{
	if (g_sig_char.si_pid && g_sig_char.si_pid != siginfo->si_pid)
		return ;
	if (!g_sig_char.si_pid)
		g_sig_char.si_pid = siginfo->si_pid;
	if (signo == SIGUSR1)
	{
		g_sig_char.buf = g_sig_char.buf | (1 << 7 - g_sig_char.idx);
		g_sig_char.idx++;
	}
	else if (signo == SIGUSR2)
		g_sig_char.idx++;
	if (g_sig_char.idx >= 7)
	{
		write(1, &g_sig_char.buf, 1);
		write(1, "\n", 1);
		g_sig_char.si_pid = 0;
		g_sig_char.idx = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	struct sigaction	*oldact;
	char				*pid_str;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = mt_sigaction;
	pid_str = ft_itoa(getpid());
	ft_putstr_fd(pid_str, 1);
	if (sigaction(SIGUSR1, &act, oldact) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	while (1)
		pause();
}
