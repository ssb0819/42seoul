/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2024/01/12 19:37:13 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static t_files	*files;
	t_files			*file;
	ssize_t			r_bytes;
	size_t			buf_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	file = find_cur_file(&files, fd);
	if (!file)
		return ((void *)0);
	buf_size = BUFFER_SIZE;
	while (buf_size < 1024)
		buf_size *= 2;
	while (1)
	{
		r_bytes = read_next(fd, file, buf_size);
		if (r_bytes == -1)
		{
			remove_file(&files, fd);
			return ((void *)0);
		}
		else if (r_bytes == 0 || ft_strchr(file->content, '\n', file->len) > 0)
			break ;
	}
	return (parse_by_nl(&files, file));
}

ssize_t	read_next(int fd, t_files *cur_file, size_t buf_size)
{
	size_t	i;
	size_t	*len;
	char	*content;
	char	*new_buf;

	len = &(cur_file->len);
	content = cur_file->content;
	new_buf = (char *)malloc(*len + buf_size + 1);
	if (!new_buf)
		return (-1);
	i = 0;
	while (i < *len)
	{
		*new_buf = content[i++];
		new_buf++;
	}
	free(content);
	content = new_buf - i;
	cur_file->content = content;
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

char	*parse_by_nl(t_files **files, t_files *cur_file)
{
	char	*result;
	char	*backup;
	ssize_t	index_nl;

	index_nl = ft_strchr(cur_file->content, '\n', cur_file->len);
	if (index_nl == -1)
		result = ft_substr(cur_file->content, 0, cur_file->len);
	else
	{
		result = ft_substr(cur_file->content, 0, index_nl + 1);
		if (result)
			backup = ft_substr(cur_file->content, index_nl + 1, cur_file->len);
		else
			backup = (void *)0;
	}
	if (index_nl == -1 || !result || !backup)
		remove_file(files, cur_file->fd);
	else
	{
		free(cur_file->content);
		cur_file->content = backup;
		cur_file->len = cur_file->len - (size_t)index_nl - 1;
	}
	return (result);
}
