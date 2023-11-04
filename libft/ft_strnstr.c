/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:12:57 by subson            #+#    #+#             */
/*   Updated: 2023/11/04 20:40:48 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	issame_str(const char *str, const char *needle, size_t len)
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (needle == 0 || ft_strlen(needle) == 0)
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
