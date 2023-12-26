/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2023/12/26 21:08:05 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	result = (void *)0;
	if (prev)
	{
		if (check_prev(&result, &prev))
			return (result);
	}
	read_line(&result, &prev, fd);
	return (result);
}

int	check_prev(char **result, char **prev)
{
	int		i;
	char	*tmp_prev;

	tmp_prev = *prev;
	i = ft_strchr(tmp_prev, '\n');
	if (i >= 0)
	{
		*result = ft_substr(tmp_prev, 0, i + 1);
		*prev = ft_substr(tmp_prev, i + 1, -1);
		free(tmp_prev);
		return (1);
	}
	else
	{
		*result = *prev;
		*prev = (void *)0;
		return (0);
	}
}

void	read_line(char **result, char **prev, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	ssize_t	r_byte;
	char	*tmp;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (1)
	{
		r_byte = read(fd, buffer, BUFFER_SIZE);
		if (!r_byte)
		{
			free(*prev);
			break ;
		}
		i = ft_strchr(buffer, '\n');
		if (i >= 0)
		{
			tmp = ft_substr(buffer, 0, i + 1);
			*result = ft_strjoin(*result, tmp);
			free(tmp);
			tmp = *prev;
			*prev = ft_substr(buffer, i + 1, -1);
			free(tmp);
			break ;
		}
		else
			*result = ft_strjoin(*result, buffer);
	}
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
	free(s1);
	return (res);
}
