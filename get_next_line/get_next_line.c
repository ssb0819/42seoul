/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:24 by subson            #+#    #+#             */
/*   Updated: 2023/12/06 18:45:17 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	t_buffer	*list;
	ssize_t		read_byte;
	char		c;
	char		*str;

	list = (void *)0;
	while (1)
	{
		read_byte = read(fd, &c, 1);
		if (read_byte > 0)
		{
			add_char(list, c);
			if (c == '\n')
				break ;
		}
		else if (read_byte == 0)
			break ;
		else
		{
			free_all(list);
			return ((void *)0);
		}
	}
	str = make_str(list);
	return (free_all(list), str);
}

void	add_char(t_buffer *list, char c)
{
	t_buffer	*last_node;
	char		*buf;
	int			idx;

	last_node = get_last(list);
	buf = last_node->buffer;
	idx = last_node->buf_idx;
	buf[idx] = c;
	last_node->buf_idx++;
}

t_buffer	*get_last(t_buffer *list)
{
	t_buffer	*last;
	t_buffer	*new_node;

	while (list)
	{
		last = list;
		list = list->next;
	}
	if (list == 0 || last->buf_idx == BUFFER_SIZE)
	{
		new_node = (t_buffer *)malloc(sizeof(t_buffer));
		new_node->buf_idx = 0;
		new_node->buffer = (char *)malloc(BUFFER_SIZE);
		new_node->next = (void *)0;
		if (list == 0)
		{
			list = new_node;
		}
		else
			last->next = new_node;
		last = new_node;
	}
	return (last);
}

void	free_all(t_buffer *list)
{
	t_buffer	*next;

	while (list)
	{
		next = list->next;
		free(list->buffer);
		free(list);
		list = next;
	}
}

char	*make_str(t_buffer *list)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	len = get_total_len(list);
	str = (char *)malloc(len);
	if (!str)
		return ((void *)0);
	while (i < len)
	{
		j = 0;
		while (j < list->buf_idx)
		{
			str[i] = (list->buffer)[j];
			i++;
			j++;
		}
		list = list->next;
	}
	return (str);
}

size_t	get_total_len(t_buffer *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		len += (list->buf_idx - 1);
		list = list->next;
	}
	return (len);
}
