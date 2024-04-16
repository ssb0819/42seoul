/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:39:57 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 18:10:20 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_BONUS_H
# define MT_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

# define TWO_BYTE 192	/* 1100 0000 */
# define THREE_BYTE 224	/* 1110 0000 */
# define FOUR_BYTE 240	/* 1111 0000 */

typedef struct s_signal_buffer
{
	pid_t			si_pid;
	unsigned char	buf[4];
	int				idx;
	int				byte_cnt;
}				t_signal_buffer;

/* mt_utils.c */
void	send_signal(int pid, unsigned char c, int cnt);

#endif