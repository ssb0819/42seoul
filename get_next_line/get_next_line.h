/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:54 by subson            #+#    #+#             */
/*   Updated: 2023/12/06 18:44:32 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	char			*buffer;
	size_t			buf_idx;
	struct s_buffer	*next;
}	t_buffer;

char		*get_next_line(int fd);
void		add_char(t_buffer *list, char c);
t_buffer	*get_last(t_buffer *list);
void		free_all(t_buffer *list);
char		*make_str(t_buffer *list);
size_t		get_total_len(t_buffer *list);

#endif