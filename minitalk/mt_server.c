/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/04/19 14:33:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

// static void	print_char_bit(char c, int cnt)
// {
// 	if (cnt < 7)
// 		print_char_bit(c >> 1, ++cnt);
// 	if ((c & (char)1) == 1)
// 		write(1, "1 ", 2);
// 	else
// 		write(1, "0 ", 2);
// }

typedef struct s_sig_char
{
	pid_t			si_pid;
	unsigned char	buf;
	int				idx;
}				t_sig_char;

t_sig_char	g_sig_char;

void	mt_translate_signal(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	bit = -128;

	context = (void *)0;
	if (!g_sig_char.si_pid)
		g_sig_char.si_pid = siginfo->si_pid;
	else if (g_sig_char.si_pid != siginfo->si_pid)
	{
		ft_bzero(&g_sig_char, sizeof(t_sig_char));
		g_sig_char.si_pid = siginfo->si_pid;
	}
	if (signo == SIGUSR1)
	{
		g_sig_char.buf = g_sig_char.buf | (bit >> g_sig_char.idx);
		//write(1, "1 ", 2);
	}
	else if (signo == SIGUSR2)
	{
		//write(1, "0 ", 2);
	}
	g_sig_char.idx++;
	if (g_sig_char.idx == 8)
	{
		write(1, &g_sig_char.buf, 1);
		// write(1, "\ndebug-char:", 12);
		// print_char_bit(g_sig_char.buf, 0);
		// write(1, "\n", 1);
		ft_bzero(&g_sig_char, sizeof(t_sig_char));
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
	free(pid_str);
	sigaction(SIGUSR1, &act, (void *)0); // 예외처리?
	sigaction(SIGUSR2, &act, (void *)0);
	while (1)
		pause();
}
