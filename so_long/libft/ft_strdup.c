/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:51:59 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:18:08 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	if (!s1)
		return ((void *)0);
	len = ft_strlen(s1);
	cpy = (char *)ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return ((void *)0);
	ft_strlcpy(cpy, s1, len + 1);
	return (cpy);
}
