/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:54:18 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:23:26 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx;
	size_t	result;

	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		result = src_len + dst_len;
	idx = dst_len;
	while (idx + 1 < dstsize && *src)
	{
		dst[idx] = *src;
		idx++;
		src++;
	}
	dst[idx] = '\0';
	return (result);
}
