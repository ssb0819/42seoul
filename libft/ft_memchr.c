/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:16:00 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 11:54:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	while (n > 0)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
		n--;
	}
	return (0);
}
