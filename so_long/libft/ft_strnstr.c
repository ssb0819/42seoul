/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:12:57 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 13:03:00 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int static	issame_str(const char *str, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			if (issame_str(haystack, needle, len))
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}

int static	issame_str(const char *str, const char *needle, size_t len)
{
	int	i;

	i = 0;
	while (needle[i] && len)
	{
		if (str[i] != needle[i])
			return (0);
		i++;
		len--;
	}
	if (needle[i])
		return (0);
	return (1);
}
