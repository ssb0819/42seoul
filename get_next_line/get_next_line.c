/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2024/01/12 15:12:29 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		r_bytes;
	size_t		len;
	size_t		buf_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	len = ft_strlen(buffer);
	buf_size = BUFFER_SIZE;
	while (buf_size < 1024)
		buf_size *= 2;
	while (1)
	{
		r_bytes = read_next(fd, &buffer, &len, buf_size);
		if (r_bytes == -1)
		{
			free(buffer);
			buffer = (void *)0;
			return ((void *)0);
		}
		else if (r_bytes == 0 || ft_strchr(buffer, '\n', len) > 0)
			break ;
	}
	return (parse_by_nl(&buffer, ft_strchr(buffer, '\n', len), len));
}

ssize_t	read_next(int fd, char **buffer, size_t *len, size_t buf_size)
{
	char	*new_buf;
	size_t	i;

	new_buf = (char *)malloc(*len + buf_size + 1);
	if (!new_buf)
		return (-1);
	i = 0;
	while (i < *len)
	{
		*new_buf = (*buffer)[i++];
		new_buf++;
	}
	free(*buffer);
	*buffer = (void *)0;
	*buffer = new_buf - i;
	return (call_read(fd, new_buf, len, buf_size));
}

ssize_t	call_read(int fd, char *buffer, size_t *len, size_t buf_size)
{
	size_t	i;
	ssize_t	r_bytes;

	i = 0;
	while (i * BUFFER_SIZE < buf_size)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes <= 0)
			return (r_bytes);
		else
		{
			*len += r_bytes;
			buffer += BUFFER_SIZE;
			i++;
		}
	}
	return (1);
}

char	*parse_by_nl(char **buffer, ssize_t index_nl, size_t len)
{
	char	*result;
	char	*backup;

	if (index_nl == -1)
		result = ft_substr(*buffer, 0, len);
	else
	{
		result = ft_substr(*buffer, 0, index_nl + 1);
		if (result)
			backup = ft_substr(*buffer, index_nl + 1, len);
		else
			backup = (void *)0;
	}
	free(*buffer);
	if (index_nl == -1)
		*buffer = (void *)0;
	else
		*buffer = backup;
	return (result);
}
