/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:34:58 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:25:25 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	alloc_size;
	size_t	i;
	char	*subs;

	if (!s)
		return ((void *)0);
	slen = ft_strlen(s);
	if (start > slen)
		alloc_size = 0;
	else
		alloc_size = slen - start;
	if (alloc_size > len)
		alloc_size = len;
	subs = (char *)ft_calloc(alloc_size + 1, sizeof(char));
	if (!subs)
		return ((void *)0);
	i = 0;
	while (i < alloc_size)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}
