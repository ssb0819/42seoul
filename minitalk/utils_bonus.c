/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:42:03 by subson            #+#    #+#             */
/*   Updated: 2024/04/24 23:52:17 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_bonus.h"

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(50);
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	send_str(pid_t pid, unsigned char *buffer, int len)
{
	int	i;

	i = 0;
	if (!buffer)
		return ;
	while (i < len)
		send_char(pid, buffer[i++]);
}

int	get_encoding_bytes_len(unsigned char first_c)
{
	if (first_c <= ONE_BYTE_MAX)
		return (1);
	else if (TWO_BYTE_MIN <= first_c && first_c < THREE_BYTE_MIN)
		return (2);
	else if (THREE_BYTE_MIN <= first_c && first_c < FOUR_BYTE_MIN)
		return (3);
	else if (FOUR_BYTE_MIN <= first_c)
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
