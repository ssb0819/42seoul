/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:38:16 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 16:03:15 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
int	static	get_cnt(char const *s, char c);
char static	**set_strs(char **strs, char *s, int cnt, char delimeter);
void static	free_all(char **strs, int n);

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**strs;

	if (s == NULL)
		return (NULL);
	cnt = get_cnt(s, c);
	strs = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	strs = set_strs(strs, (char *)s, cnt, c);
	return (strs);
}

int	static	get_cnt(char const *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			cnt++;
		i++;
	}
	return (cnt);
}

char static	**set_strs(char **strs, char *str, int cnt, char delimeter)
{
	int		each_len;
	int		i;

	i = 0;
	while (*str == delimeter)
		str++;
	while (i < cnt)
	{
		each_len = ft_strchr(str, delimeter) - str;
		if (each_len)
		{
			strs[i] = ft_substr(str, 0, each_len);
			if (strs[i] == NULL)
			{
				free_all(strs, i);
				return (NULL);
			}
			i++;
		}
		str = str + each_len + 1;
	}
	strs[i] = 0;
	return (strs);
}

void static	free_all(char **strs, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		free(strs[i++]);
	free(strs);
}
