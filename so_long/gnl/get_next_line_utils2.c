/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:28 by subson            #+#    #+#             */
/*   Updated: 2024/04/04 22:12:06 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

ssize_t	gnl_strchr(char *s, char c, size_t len)
{
	ssize_t	i;
	ssize_t	size;

	i = 0;
	size = len;
	if (!s)
		return (-1);
	while (i < size)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_substr(char const *s, ssize_t start, ssize_t end)
{
	char	*res;
	ssize_t	len;
	ssize_t	i;

	if (!s)
		return ((void *)0);
	len = end - start;
	if (len <= 0)
		return ((void *)0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
