/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:54 by subson            #+#    #+#             */
/*   Updated: 2024/01/12 18:29:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_files
{
	int				fd;
	void			*content;
	size_t			len;
	struct s_files	*next;
}	t_files;

char	*get_next_line(int fd);
ssize_t	read_next(int fd, t_files *cur_file, size_t buf_size);
ssize_t	call_read(int fd, char *buffer, size_t *len, size_t buf_size);
char	*parse_by_nl(t_files **files, t_files *cur_file);
size_t	ft_strlen(const char *s);
ssize_t	ft_strchr(char *s, char c, size_t len);
char	*ft_substr(char const *s, ssize_t start, size_t end);
t_files	*find_cur_file(t_files **file, int fd);
void	remove_file(t_files **files, int fd);

#endif