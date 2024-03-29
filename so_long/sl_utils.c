/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:18:31 by subson            #+#    #+#             */
/*   Updated: 2024/03/29 22:01:54 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_on_error(t_err_types e_type, char *err_msg)
{
	if (e_type == SYSTEM_ERR)
		perror(err_msg);
	else if (e_type == RUNTIME_ERR)
		ft_putstr_fd(err_msg, 2);
	exit(1);
}

int	sl_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	u_dst = dst;
	u_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		i++;
	}
	return (dst);
}
