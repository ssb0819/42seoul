/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:54 by subson            #+#    #+#             */
/*   Updated: 2024/01/12 14:42:34 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
ssize_t	read_next(int fd, char **buffer, size_t *len, size_t buf_size);
ssize_t	call_read(int fd, char *buffer, size_t *len, size_t buf_size);
char	*parse_by_nl(char **buffer, ssize_t index_nl, size_t len);
size_t	ft_strlen(const char *s);
ssize_t	ft_strchr(char *s, char c, size_t len);
char	*ft_substr(char const *s, ssize_t start, size_t end);

#endif