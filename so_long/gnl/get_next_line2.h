/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:54 by subson            #+#    #+#             */
/*   Updated: 2024/03/28 16:38:55 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FILE_ERROR -3
# define FILE_END -2
# define NO_NL -1

ssize_t	get_next_line(int fd, char **next_line);
ssize_t	make_new_str(char **str, size_t len, size_t repeat_num);
ssize_t	read_next(int fd, char *str, size_t *len, size_t repeat_num);
char	*parse_by_nl(char **str, size_t len);
size_t	ft_strlen(const char *s);
ssize_t	ft_strchr(char *s, char c, size_t len);
char	*ft_substr(char const *s, ssize_t start, ssize_t end);

#endif