/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:26:10 by subson            #+#    #+#             */
/*   Updated: 2024/05/22 14:45:57 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#define END_SIGN 0

typedef struct s_signal_buffer
{
	pid_t			si_pid;
	unsigned char	c;
	int				sig_cnt;
	unsigned char	buffer[1024];
	int				buf_idx;
}				t_signal_buffer;

t_signal_buffer	g_buf;

static void	flush_buffer(void)
{
	if (!g_buf.buf_idx)
		return ;
	write(1, &g_buf.buffer, g_buf.buf_idx);
	g_buf.buf_idx = 0;
}

static void	sig_to_char(int signo, siginfo_t *siginfo, void *context)
{
	const unsigned char	one_bit = 1;

	context = (void *)0;
	if (g_buf.si_pid && g_buf.si_pid != siginfo->si_pid)
	{
		flush_buffer();
		g_buf.sig_cnt = 0;
	}
	g_buf.si_pid = siginfo->si_pid;
	if (signo == SIGUSR1)
		g_buf.c = g_buf.c | (one_bit << (7 - g_buf.sig_cnt));
	else
		g_buf.c = g_buf.c & (~one_bit << (7 - g_buf.sig_cnt));
	g_buf.sig_cnt++;
	if (g_buf.sig_cnt == 8)
	{
		g_buf.sig_cnt = 0;
		if (g_buf.c != END_SIGN)
		{
			g_buf.buffer[g_buf.buf_idx] = g_buf.c;
			g_buf.buf_idx++;
		}
		if (g_buf.c == END_SIGN || g_buf.buf_idx == 1024)
			flush_buffer();
	}
}

int	main(void)
{
	struct sigaction	act; // 시그널 관련 설정 저장할 수 있는 구조체
	char				*pid_str;

	sigemptyset(&act.sa_mask); 
	sigaddset(&act.sa_mask, SIGUSR1); // 블락할 시그널 설정
	sigaddset(&act.sa_mask, SIGUSR2); // 블락할 시그널 설정
	act.sa_flags = SA_SIGINFO; // 시그널핸들러 함수 2종류(sa_handler, sa_sigaction) 중 sa_sigaction사용하겠다는 플래그 설정 
	act.sa_sigaction = sig_to_char; // 시그널 핸들러 함수 설정
	pid_str = ft_itoa(getpid());
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd("\n", 1);
	free(pid_str);
	if (sigaction(SIGUSR1, &act, (void *)0) == -1) // 설정한 act구조체 등록 (SIGUSR1 시그널 발생 시 act에 설정된 대로 동작)
		exit(1);
	if (sigaction(SIGUSR2, &act, (void *)0) == -1) // 설정한 act구조체 등록 (SIGUSR2 시그널 발생 시 act에 설정된 대로 동작)
		exit(1);
	while (1)
	{
		if (usleep(100000) == 0)
			flush_buffer();
	}
}
