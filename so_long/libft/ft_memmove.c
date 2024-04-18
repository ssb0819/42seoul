/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:33 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:10:38 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;

	if (!dst || !src)
		return ((void *)0);
	if (src == dst)
		return (dst);
	else if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		u_dst = dst;
		u_src = (unsigned char *)src;
		while (len)
		{
			len--;
			u_dst[len] = u_src[len];
		}
		return (dst);
	}
}
