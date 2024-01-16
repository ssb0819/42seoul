/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:28 by subson            #+#    #+#             */
/*   Updated: 2024/01/16 14:50:15 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
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

ssize_t	ft_strchr(char *s, char c, size_t len)
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

char	*ft_substr(char const *s, ssize_t start, size_t end)
{
	char	*res;
	ssize_t	len;
	ssize_t	i;

	if (!s)
		return ((void *)0);
	len = (ssize_t)end - start;
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

t_files	*find_cur_file(t_files **file_p, int fd)
{
	t_files	*new_file;

	if (*file_p)
	{
		while (*file_p)
		{
			if ((*file_p)->fd == fd)
				return (*file_p);
			file_p = &((*file_p)->next);
		}
	}
	new_file = malloc(sizeof(t_files));
	if (!new_file)
		return ((void *)0);
	new_file->fd = fd;
	new_file->len = 0;
	new_file->str = (void *)0;
	new_file->next = (void *)0;
	*file_p = new_file;
	return (new_file);
}

int	remove_file(t_files **next_p, int fd)
{
	t_files	*cur;

	if (!next_p)
		return (0);
	cur = *next_p;
	while (cur)
	{
		if (cur->fd == fd)
		{
			*next_p = cur->next;
			free(cur->str);
			free(cur);
			return (fd);
		}
		next_p = &(cur->next);
		cur = cur->next;
	}
	return (0);
}
