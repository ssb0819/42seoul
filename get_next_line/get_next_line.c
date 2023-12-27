/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2023/12/27 16:08:19 by subson           ###   ########.fr       */
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
		free(prev);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	while (ft_strchr(cur, '\n') < 0)
	{
		r_byte = read(fd, buffer, BUFFER_SIZE);
		if (r_byte == -1)
			return ((void *)0);
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
	if (*prev)
		free(*prev);
	*prev = ft_substr(str, i + 1, -1);
	result = ft_substr(str, 0, i + 1);
	free(str);
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *(s1++);
	while (*s2)
		res[i++] = *(s2++);
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}
