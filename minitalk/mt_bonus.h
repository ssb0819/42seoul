/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:39:57 by subson            #+#    #+#             */
/*   Updated: 2024/04/24 23:34:17 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_BONUS_H
# define MT_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

# define ONE_BYTE_MAX 127	/* 0111 1111 */
# define TWO_BYTE_MIN 192	/* 1100 0000 */
# define THREE_BYTE_MIN 224	/* 1110 0000 */
# define FOUR_BYTE_MIN 240	/* 1111 0000 */

# define END_SIGN 0			/* 0000 0000 0000 0000*/
# define ERR_SIGN 65535		/* 1111 1111 1111 1111*/

typedef struct s_signal_buffer
{
	pid_t			si_pid;
	unsigned short	flag;
	unsigned char	unicode[4];
	int				sig_cnt;
	int				byte_size;
	unsigned char	buffer[1020];
	int				buf_idx;
}				t_signal_buffer;

/* utils_bonus.c */
void	send_char(pid_t pid, unsigned char c);
void	send_str(pid_t pid, unsigned char *buffer, int byte_size);
int		get_encoding_bytes_len(unsigned char first_c);
void	print_my_pid(void);

/* buffer_bonus.c */
void	sig_to_unicode(int signo, siginfo_t *siginfo, void *context);
void	init_unicode(void);
void	add_bit_to_unicode(int bit);
void	put_unicode(void);
void	flush_buffer(void);

#endif