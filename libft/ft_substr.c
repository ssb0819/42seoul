/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:34:58 by subson            #+#    #+#             */
/*   Updated: 2023/11/05 16:21:43 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	alloc_size;
	size_t	i;
	char	*subs;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if ((size_t)start > slen)
		return (NULL);
	alloc_size = slen - start;
	if (alloc_size > len)
		alloc_size = len;
	subs = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < alloc_size)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}
