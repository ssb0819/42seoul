/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:50:34 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:11:16 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	if (!dst || !src)
		return ((void *)0);
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
