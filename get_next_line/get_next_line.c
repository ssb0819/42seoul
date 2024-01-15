/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:36 by subson            #+#    #+#             */
/*   Updated: 2024/01/15 19:46:59 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	size_t		len;
	ssize_t		nl_index;
	size_t		repeat_num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	len = ft_strlen(str);
	repeat_num = 1;
	while (make_new_str(&str, len, repeat_num))
	{
		nl_index = read_next(fd, str, &len, repeat_num);
		if (nl_index == FILE_END || nl_index > NO_NL)
			return (parse_by_nl(&str, len));
		if (nl_index == FILE_ERROR)
			break ;
		repeat_num++;
	}
	free(str);
	str = (void *)0;
	return ((void *)0);
}

ssize_t	make_new_str(char **str, size_t len, size_t repeat_num)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(BUFFER_SIZE * repeat_num + len);
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = (*str)[i];
		i++;
	}
	free(*str);
	*str = new_str;
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

char	*parse_by_nl(char **str, size_t len)
{
	char	*result;
	char	*backup;
	ssize_t	nl_index;

	backup = (void *)0;
	nl_index = ft_strchr(*str, '\n', len);
	if (nl_index == NO_NL)
		result = ft_substr(*str, 0, len);
	else
	{
		result = ft_substr(*str, 0, nl_index + 1);
		if (result)
		{
			backup = ft_substr(*str, nl_index + 1, len);
			if (len - nl_index > 1 && !backup)
			{
				free(result);
				result = (void *)0;
			}
		}
	}
	free(*str);
	*str = backup;
	return (result);
}
