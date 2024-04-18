/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:42:03 by subson            #+#    #+#             */
/*   Updated: 2024/04/17 23:59:31 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

void	send_char_by_signal(pid_t pid, unsigned char c, int cnt)
{
	if (cnt < 7)
		send_char_by_signal(pid, c >> 1, ++cnt);
	if (c % 2 == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(10);
}

void	send_unicode_by_sig(pid_t pid, unsigned char *buffer, int byte_len)
{
	int	i;

	i = 0;
	while (i < byte_len)
		send_char_by_signal(pid, buffer[i++], 0);
}

int	get_encoding_bytes(unsigned char first_c)
{
	if (first_c <= ONE_BYTE)
		return (1);
	else if (TWO_BYTE <= first_c && first_c < THREE_BYTE)
		return (2);
	else if (THREE_BYTE <= first_c && first_c < FOUR_BYTE)
		return (3);
	else if (FOUR_BYTE <= first_c)
		return (4);
	else
		return (0);
}

void	print_my_pid(void)
{
	char	*pid_str;

	pid_str = ft_itoa(getpid());
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd("\n", 1);
	free(pid_str);
}
