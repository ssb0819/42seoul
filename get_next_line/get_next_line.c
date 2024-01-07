/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2024/01/07 18:50:43 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*cur;
	ssize_t		r_byte;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	cur = ft_strdup(prev);
	if (prev)
	{
		free(prev);
		prev = (void *)0;
	}
	while (ft_strchr(cur, '\n') < 0)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
		r_byte = read(fd, buffer, BUFFER_SIZE);
		if (r_byte == -1)
		{
			if (cur)
				free(cur);
			return ((void *)0);
		}
		if (r_byte == 0)
			return (cur);
		else
			cur = ft_strjoin(cur, buffer);
	}
	return (parse_str(cur, &prev));
}

char	*parse_str(char *str, char **prev)
{
	int		i;
	char	*result;

	i = ft_strchr(str, '\n');
	result = ft_substr(str, 0, i + 1);
	*prev = ft_substr(str, i + 1, -1);
	free(str);
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return ((void *)0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		free(s1);
		return ((void *)0);
	}
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
