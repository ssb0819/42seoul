/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:54 by subson            #+#    #+#             */
/*   Updated: 2024/01/16 15:35:03 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FILE_ERROR -3
# define FILE_END -2
# define NO_NL -1

typedef struct s_file
{
	int				fd;
	void			*str;
	size_t			len;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
ssize_t	make_new_str(t_file *file, size_t repeat_num);
ssize_t	read_next(int fd, char *str, size_t *len, size_t repeat_num);
char	*parse_by_nl(t_file **files, t_file *file);
size_t	ft_strlen(const char *s);
ssize_t	ft_strchr(char *s, char c, size_t len);
char	*ft_substr(char const *s, ssize_t start, size_t end);
t_file	*find_cur_file(t_file **file, int fd);
int		remove_file(t_file **file_p, int fd);

#endif