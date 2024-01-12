/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:28 by subson            #+#    #+#             */
/*   Updated: 2024/01/12 19:00:44 by subson           ###   ########.fr       */
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

t_files	*find_cur_file(t_files **files, int fd)
{
	t_files	**file;
	t_files	*new_file;

	if (*files)
	{
		file = files;
		while (*file)
		{
			if ((*file)->fd == fd)
				return (*file);
			file = &((*file)->next);
		}
	}
	new_file = malloc(sizeof(t_files));
	if (!new_file)
		return ((void *)0);
	new_file->fd = fd;
	new_file->len = 0;
	new_file->content = (void *)0;
	new_file->next = (void *)0;
	if (*files)
		*file = new_file;
	else
		*files = new_file;
	return (new_file);
}

void	remove_file(t_files **files, int fd)
{
	t_files	*file;
	t_files	*tmp;

	file = *files;
	if (file->fd == fd)
	{
		*files = file->next;
		free(file->content);
		free(file);
	}
	else
	{
		while (file)
		{
			if (file->next->fd == fd)
			{
				tmp = file->next;
				file->next = file->next->next;
				free(tmp->content);
				free(tmp);
				return ;
			}
			file = file->next;
		}
	}
}
