/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2024/01/16 15:33:06 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file	*file_lst;
	t_file			*file;
	ssize_t			nl_index;
	size_t			repeat_num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	file = find_cur_file(&file_lst, fd);
	if (!file)
		return ((void *)0);
	repeat_num = 1;
	while (make_new_str(file, repeat_num))
	{
		nl_index = read_next(fd, file->str, &(file->len), repeat_num);
		if (nl_index == FILE_ERROR)
			break ;
		if (nl_index == FILE_END || nl_index > NO_NL)
			return (parse_by_nl(&file_lst, file));
		repeat_num++;
	}
	remove_file(&file_lst, fd);
	return ((void *)0);
}

ssize_t	make_new_str(t_file *file, size_t repeat_num)
{
	char	*str;
	char	*new_str;
	size_t	len;
	size_t	i;

	str = file->str;
	len = file->len;
	new_str = malloc(BUFFER_SIZE * repeat_num + len);
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	file->str = new_str;
	return (1);
}

ssize_t	read_next(int fd, char *str, size_t *len, size_t repeat_num)
{
	char	buffer[BUFFER_SIZE];
	size_t	i;
	ssize_t	j;
	ssize_t	r_bytes;

	i = 0;
	while (i < repeat_num)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
			return (FILE_ERROR);
		else if (r_bytes == 0)
			return (FILE_END);
		else
		{
			j = 0;
			while (j < r_bytes)
				str[(*len)++] = buffer[j++];
			r_bytes = ft_strchr(str, '\n', *len);
			if (r_bytes != NO_NL)
				break ;
			i++;
		}
	}
	return (r_bytes);
}

char	*parse_by_nl(t_file **file_lst, t_file *file)
{
	char	*result;
	char	*backup;
	ssize_t	nl_index;

	nl_index = ft_strchr(file->str, '\n', file->len);
	if (nl_index == NO_NL)
		result = ft_substr(file->str, 0, file->len);
	else
	{
		result = ft_substr(file->str, 0, nl_index + 1);
		backup = ft_substr(file->str, nl_index + 1, file->len);
		if (!result || (file->len - nl_index > 1 && !backup))
		{
			free(result);
			free(backup);
			remove_file(file_lst, file->fd);
			return ((void *)0);
		}
		free(file->str);
		file->str = backup;
		file->len = file->len - nl_index - 1;
		return (result);
	}
	remove_file(file_lst, file->fd);
	return (result);
}
