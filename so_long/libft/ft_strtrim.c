/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:03 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:24:59 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start_i;
	size_t	len;

	if (!s1 || !set)
		return ((void *)0);
	start_i = 0;
	len = ft_strlen(s1);
	if (!len)
	{
		res = ft_calloc(1, sizeof(char));
		if (!res)
			return ((void *)0);
		return (res);
	}
	while (ft_strchr(set, s1[start_i]) != 0)
		start_i++;
	len--;
	while (ft_strchr(set, s1[len]) != 0)
		len--;
	len = len - start_i + 1;
	res = ft_substr(s1, (unsigned int)start_i, len);
	return (res);
}
